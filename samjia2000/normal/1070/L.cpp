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

const int N = 2005;
const int M = 20005;

bitset<N>f[N];
int n,m;
struct edge{
	int x,nxt;
}e[M];
int h[N],tot;
int d[N];

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

int fir[N],num[N];
int val[N];

bool cmp(int x,int y){return fir[x]<fir[y];}

void solve(){
	n=get();m=get();
	fo(i,1,n)d[i]=h[i]=0;
	tot=0;
	fo(i,1,m){
		int x=get(),y=get();
		inse(x,y),inse(y,x);
		d[x]++,d[y]++;
	}
	bool pd=1;
	fo(i,1,n)pd&=(d[i]%2==0);
	if (pd){
		printf("1\n");
		fo(i,1,n)printf("1%c",i==n?'\n':' ');
		return;
	}
	fo(i,1,n){
		f[i].reset();
		f[i][0]=0;
		for(int p=h[i];p;p=e[p].nxt)f[i][e[p].x]=1;
		if (d[i]&1)f[i][0]=f[i][i]=1;
		fir[num[i]=i]=0;
	}
	fir[0]=n+1;
	fo(i,1,n){
		fir[i]=n+1;
		fo(x,1,n)if (f[i][x]){fir[i]=x;break;}
		if (fir[i]>n)continue;
		fo(j,i+1,n)	if (f[j][fir[i]])f[j]^=f[i];
	}
	sort(num+1,num+1+n,cmp);
	fo(i,1,n)val[i]=0;
	fd(i,n,1){
		int x=num[i],y=num[i+1];
		if (fir[x]<fir[y]){
			val[fir[x]]=f[x][0];
			fo(w,fir[y],n)if (f[x][w])val[fir[x]]^=val[w];
		}
	}
	printf("2\n");
	fo(i,1,n)printf("%d%c",val[i]+1,i==n?'\n':' ');
}

int main(){
	for(int T=get();T;T--)solve();
	return 0;
}