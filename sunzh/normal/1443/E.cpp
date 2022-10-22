#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
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
int n,Q;
long long sum[200010];
long long tot;
long long fac[20];
int max(int x,int y){
	return x>y?x:y; 
}
int min(int x,int y){
	return x<y?x:y; 
}
signed main(){
	n=read(),Q=read();
	for(int i=1;i<=n-15;++i) sum[i]=sum[i-1]+i;
	fac[0]=1;
	for(int i=1;i<=15;++i) fac[i]=fac[i-1]*i;
	set<int>st;
	int l,r,p,op,cnt;
	long long tmp;
	long long ans;
	while(Q--){
		op=read();
		if(op==1){
			l=read(),r=read();
			ans=0;
			if(l<=n-15) ans+=sum[min(r,n-15)]-sum[l-1];
			tmp=tot;st.clear();
			for(int i=max(1,n-14);i<=n;++i) st.insert(i);
//			for(int i:st)printf("%d ",i);
			for(int i=max(1,n-14);i<=r;++i){
				p=n-i;
				if(!p){
					if(i>=l&&i<=r) ans+=(*st.begin());
				}
				else{
					cnt=tmp/fac[p];
					if(cnt>st.size()) cnt=st.size();
					tmp-=cnt*fac[p];
					auto it=st.begin();
					while(cnt&&it!=st.end()){
						++it;--cnt;
					}
					if(i>=l&&i<=r) ans+=(*it);
					st.erase(it);
				}
			}
			printf("%lld\n",ans);
		}
		else{
			int x=read();
			tot+=x;tot%=fac[min(n,15)];
		}
	}
}