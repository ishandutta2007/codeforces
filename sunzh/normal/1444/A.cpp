#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int p,q;
const int n=1000000;
int prime[1000010];
bool vis[1000010];
int tot;
void so(){
    vis[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]) prime[++tot]=i;
        for(int j=1;prime[j]*i<=n;j++){
            vis[prime[j]*i]=1;
            if(i%prime[j]==0) break ;
        }
    }
}
signed main(){
	T=read();so();
	while(T--){
		p=read(),q=read();
//		printf("%lld %lld\n",p,q);
		if(p%q!=0){
			printf("%lld\n",p);
		}
		else{
			int ans=1;
			int tmp=q;
			for(int k=1;k<=tot&&prime[k]<tmp;++k){
				int i=prime[k]; 
//				printf("i:%lld ",i);
				int cnt=0;
				if(tmp%i==0){
					int o=1;
					while(tmp%i==0) tmp/=i,++cnt,o*=i;
//					printf("o:%lld\n",o);
					int t=p;
					while(t%o==0) t/=i;
//					printf("t:%lld\n",t);
					ans=max(ans,t);
				}
			}
			if(tmp>1){
				int t=p;
				while(t%tmp==0) t/=tmp;
				ans=max(ans,t);
			}
			printf("%lld\n",ans);
		}
	}
}