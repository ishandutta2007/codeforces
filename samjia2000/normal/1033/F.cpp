#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int L = 7e5+5;

int w,n,m;
int cnt[5000];
LL f[L];
int tw[5000];
int fi[20],se[20];
int id[5000];

int main(){
	w=get();n=get();m=get();
	fo(i,1,n){
		int x=get();
		cnt[x]++;
	}
	fo(i,0,(1<<w)-1){
		int i_=0;
		fd(x,w-1,0)i_=(i_*3)+((i&(1<<x))>0);
		f[tw[i]=i_]=cnt[i];
	}
	int lim=1;
	fo(i,1,w)lim=lim*3;
	for(int i_=1;i_<(1<<w);i_<<=1)
		for(int j_=0;j_<(1<<w);j_+=(i_<<1)){
			int i=tw[i_],j=tw[j_];
			for(int k=0;k<i;k++){
				LL l=f[j+k],r=f[i+j+k];
				f[j+k]=l+r;
				f[i+j+k]=l;
				f[(i<<1)+j+k]=r;
			}
		}
	fo(i,0,lim-1)f[i]=f[i]*f[i];
	for(int i=1;i<lim;i*=3)
		for(int j=0;j<lim;j+=(i*3))
			for(int k=0;k<i;k++){
				f[j+k]-=f[i+j+k];
				f[j+k]-=f[(i<<1)+j+k];
			}
	fo(cas,1,m){
		char s[20];
		scanf("%s",s);
		reverse(s,s+w);
		fo(i,0,w-1)fi[i]=se[i]=-1;
		fo(i,0,w-1){
			if (s[i]=='A')fi[i]=1,se[i]=0;
			if (s[i]=='O')fi[i]=1,se[i]=-1;
			if (s[i]=='X')fi[i]=1,se[i]=2;
			if (s[i]=='a')fi[i]=2,se[i]=-1;
			if (s[i]=='o')fi[i]=2,se[i]=0;
			if (s[i]=='x')fi[i]=0,se[i]=-1;
		}
		fo(i,0,(1<<w)-1)id[i]=0;
		for(int i=(1<<(w-1)),x=w-1;i;i/=2,x--)
			for(int j=0;j<(1<<w);j+=(i<<1)){
				if (id[j]==-1)id[i+j]=-1;
				else{
					if (se[x]==-1)id[i+j]=-1;else id[i+j]=id[j]*3+se[x];
					id[j]=id[j]*3+fi[x];
				}
			}
		LL ans=0;
		fo(i,0,(1<<w)-1)if (id[i]!=-1)ans=ans+f[id[i]];
		printf("%I64d\n",ans);
	}
	return 0;
}