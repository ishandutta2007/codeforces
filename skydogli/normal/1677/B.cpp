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
#define MN 1000005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m;
char ch[MN];
int ans[MN],ok[MN],r[MN];
signed main(){
	T=read();
	while(T--){
		n=read();m=read();
		scanf("%s",ch+1);
		int re=0;
		for(int i=0;i<=m;++i)ok[i]=r[i]=0;
		for(int i=1;i<=n*m;++i){
			int j=i;
			if(ch[i]=='1'){
				if(!ok[(i-1)%m])ok[(i-1)%m]=1,re++;
			}
			ans[i]=re;
		}
		for(int i=0;i<=n*m;++i)ok[i]=0;
		for(int i=1;i<=n*m;++i){
			if(ch[i]=='0'){
				int j=i;
				while(ch[j+1]=='0')j++;
				for(int k=j;i+m-1<=k;--k){
					ok[k]=1;
				}
				i=j;
			}
		}
		int lst=n*m;
		for(int i=1;i<=n*m;++i)if(ch[i]=='1'){
			lst=i;
			break;
		}
		for(int i=1;i<=n*m;++i){
			if(ok[i]){
				r[(i-1)%m]++;
			}
			printf("%lld ",i/m+(i%m!=0&&lst<=(i-1)%m+1)-r[(i-1)%m]+ans[i]);
		}
		puts("");
	}
	return 0;
}