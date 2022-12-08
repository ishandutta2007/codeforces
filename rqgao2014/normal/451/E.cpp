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

const int N=25,mod=1e9+7;
int n;
ll a[N],k,inv[N];


inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}
	return ans;
}
inline int c(ll x,int y){
	if(x<y) return 0;
	int ans=1;
	for(int i=0;i<y;i++)
		ans=(ll)ans*((x-i)%mod)%mod;
	for(int i=1;i<=y;i++) ans=(ll)ans*inv[i]%mod;
	return ans;
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=20;i++) inv[i]=exp(i,mod-2);
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		int t=0;ll s=k;
		for(int j=0;j<n;j++)
			if(i&(1<<j)) t++;
		for(int j=1;j<=n;j++)
			if(i&(1<<j-1)) s-=a[j]+1;
		if(s<0) continue;
		if(t&1) ans=(ans+mod-c(s+n-1,n-1))%mod;  else ans=(ans+c(s+n-1,n-1))%mod;
	}
	printf("%d\n",ans);
}