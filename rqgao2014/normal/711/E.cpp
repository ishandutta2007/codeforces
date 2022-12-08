#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int mod=1e6+3,md=mod-1;

inline int exp(int x,int y){
//	printf("%d %d\n",x,y);
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}
	return ans;
}
ll n,k;

inline bool check(ll k,ll n){
	bool isok=1;
	for(;n;n--){
		if(k&1) isok=0;
		k=k/2;
		if(k==1&&isok) return 1;
		if(k==0) return 1;
	}
	return 0;
}

int main(){
	cin>>n>>k;
	if(!check(k,n)){
		puts("1 1");
		return 0;
	}
//	debuge;
	int ti=n%md,tti;
	k--;
	for(int i=1;i<=62;i++)
		ti=(ti+(k/(1ll<<i))%md)%md;
//	printf("%d\n",ti);
	k++;
//	debuge;
	tti=(ll)(n%md)*(k%md)%md-ti;
	if(tti<0) tti+=md;
	if(k>=(ll)mod) printf("%d %d\n",exp(2,tti),exp(2,tti));
	else{
//		debuge;
		int ans=1,tmp=exp(2,(int)(n%md));
		for(int i=1;i<=k;i++){
			int t=tmp-i+1;
			if(t<0) t+=mod;
//			printf("%d ",t);
			ans=(ll)ans*t%mod;
		}
//		printf("%d\n",ans);
		ans=(exp(2,tti)-(ll)ans*exp(exp(2,ti),mod-2)%mod+mod)%mod;
		printf("%d %d\n",ans,exp(2,tti));
	}
	return 0;
}