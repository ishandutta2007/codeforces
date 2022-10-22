#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 600005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m;
char a[MN],b[MN],c[MN];
signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s%s%s",a+1,b+1,c+1);
		int pa=1,pb=1,pc=1,len=0;
		for(int i=1;i<=n*3&&max(max(pa,pb),pc)<=n*2;++i){
			len++;
			int t[2];t[0]=t[1]=0;
			t[a[pa]-'0']++;
			t[b[pb]-'0']++;
			t[c[pc]-'0']++;
			if(t[0]>t[1]){
				putchar('0');
				if(a[pa]=='0')pa++;
				if(b[pb]=='0')pb++;
				if(c[pc]=='0')pc++;
			}
			else {
				putchar('1');
				if(a[pa]=='1')pa++;
				if(b[pb]=='1')pb++;
				if(c[pc]=='1')pc++;
			}
		}
		if(pa>n*2){
			if(pb<pc){
				for(int i=pc;i<=n*2;++i)putchar(c[i]),len++;
			}
			else 
				for(int i=pb;i<=n*2;++i)putchar(b[i]),len++;
		}
		else if(pb>n*2){
			if(pa<pc){	
				for(int i=pc;i<=n*2;++i)putchar(c[i]),len++;
			}
			else{	
				for(int i=pa;i<=n*2;++i)putchar(a[i]),len++;
			}
		}
		else {
			if(pa<pb){	
				for(int i=pb;i<=n*2;++i)putchar(b[i]),len++;
			}
			else {	
				for(int i=pa;i<=n*2;++i)putchar(a[i]),len++;
			}
		}
		for(int i=len+1;i<=n*3;++i)putchar('0');
		puts("");
	}
	return 0;
}