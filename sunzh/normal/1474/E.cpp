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
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n;
int main(){
	T=read();
	while(T--){
		n=read();
		long long ans=0;
		vector<PII>opt;
		vector<int>a(n+1);
		for(int i=1;i<=n;++i) a[i]=i;
		for(int i=1;i<n;++i){
			if(i<=(n+1>>1)){
				ans+=1ll*(n-i)*(n-i);
				swap(a[i],a[n]);
				opt.ep(i,n); 
			}
			else{
				ans+=1ll*(i-1)*(i-1);
				swap(a[1],a[i]);opt.ep(i,1);
			}
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;++i) printf("%d ",a[i]);printf("\n");
		printf("%d\n",opt.size());
		for(int i=opt.size()-1;i>=0;--i) printf("%d %d\n",opt[i].fi,opt[i].se);
	}
}