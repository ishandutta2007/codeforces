#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);c=getchar();
	}
	return x;
}
int T;
int n;
int a[100010],dp[100010];
int Lx[100010],Rx[100010],cnt[100010];
int idx[100010];
struct ope{
    int l,r,val;
};
int main(){
    // freopen("C.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) Lx[i]=n,Rx[i]=0,cnt[i]=dp[i]=0;
		for(int i=1;i<=n;++i) a[i]=read(),Lx[a[i]]=min(Lx[a[i]],i),Rx[a[i]]=max(Rx[a[i]],i),++cnt[a[i]];
		vector<ope>tmp;
		int ans=0;
		for(int i=1;i<=n;++i) if(Rx[i]){
			++ans;
			if(Rx[i]-Lx[i]+1==cnt[i]){
				if(a[Lx[i]-1]<i) dp[Rx[i]]=max(dp[Rx[i]],dp[Lx[i]-1]+1);
				else dp[Rx[i]]=1;
			}
		}
		printf("%d\n",ans-dp[n]);
		// sort(tmp.begin(),tmp.end());
	}
}