#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 31607
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,a[30][30],b[30][30];
int val[22][2100000],rev[2100000];

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
	if(x<0) x+=MOD;
}

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return res*res%MOD;
	else return res*res%MOD*x%MOD; 
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			b[i][j]=1ll*a[i][j]*my_pow(10000,MOD-2)%MOD;
		}
	}
	int ans=1;
	{
		int vall=1,cnt=0;
		vector<int> v2;
		v2.resize(n+1,1);
		vector<vector<int> > v;
		v.resize(n+1,vector<int>(n+1,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) v[i][j]=b[i][j];
		}
		for(int i=1;i<=n;i++) rev[1<<(i-1)]=i;
		for(int i=1;i<=n;i++){
			val[i][0]=1;
			for(int j=1;j<(1<<n);j++){
				int x=rev[j&(-j)];
				val[i][j]=val[i][j^(1<<(x-1))]*v[i][x]%MOD;
			}
		}
		for(int i=0;i<(1<<n);i++){
			int tot=__builtin_popcount(i);
			int cur=vall;
			for(int j=1;j<=n;j++){
				v2[j]=val[j][i^((1<<n)-1)];
				cur=cur*val[j][i]%MOD;
			}
			int now=1;
			for(int j=1;j<=n;j++) now=now*(MOD+1-v2[j])%MOD;
			if((cnt+tot)&1) add(ans,cur*now%MOD);
			else add(ans,-cur*now%MOD);
		}
	}
	{
		int vall=1,cnt=1;
		for(int i=1;i<=n;i++) vall=vall*b[i][i]%MOD;
		vector<int> v2;
		v2.resize(n+1,1);
		vector<vector<int> > v;
		v.resize(n+1,vector<int>(n+1,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				v[i][j]=b[i][j];
				if(j==i) v[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++) rev[1<<(i-1)]=i;
		for(int i=1;i<=n;i++){
			val[i][0]=1;
			for(int j=1;j<(1<<n);j++){
				int x=rev[j&(-j)];
				val[i][j]=val[i][j^(1<<(x-1))]*v[i][x]%MOD;
			}
		}
		for(int i=0;i<(1<<n);i++){
			int tot=__builtin_popcount(i);
			int cur=vall;
			for(int j=1;j<=n;j++){
				v2[j]=val[j][i^((1<<n)-1)];
				cur=cur*val[j][i]%MOD;
			}
			int now=1;
			for(int j=1;j<=n;j++) now=now*(MOD+1-v2[j])%MOD;
			if((cnt+tot)&1) add(ans,cur*now%MOD);
			else add(ans,-cur*now%MOD);
		}
	}
	{
		int vall=1,cnt=1;
		for(int i=1;i<=n;i++) vall=vall*b[i][n-i+1]%MOD;
		vector<int> v2;
		v2.resize(n+1,1);
		vector<vector<int> > v;
		v.resize(n+1,vector<int>(n+1,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				v[i][j]=b[i][j];
				if(j==n-i+1) v[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++) rev[1<<(i-1)]=i;
		for(int i=1;i<=n;i++){
			val[i][0]=1;
			for(int j=1;j<(1<<n);j++){
				int x=rev[j&(-j)];
				val[i][j]=val[i][j^(1<<(x-1))]*v[i][x]%MOD;
			}
		}
		for(int i=0;i<(1<<n);i++){
			int tot=__builtin_popcount(i);
			int cur=vall;
			for(int j=1;j<=n;j++){
				v2[j]=val[j][i^((1<<n)-1)];
				cur=cur*val[j][i]%MOD;
			}
			int now=1;
			for(int j=1;j<=n;j++) now=now*(MOD+1-v2[j])%MOD;
			if((cnt+tot)&1) add(ans,cur*now%MOD);
			else add(ans,-cur*now%MOD);
		}
	}
	{
		int vall=1,cnt=2;
		for(int i=1;i<=n;i++) vall=vall*b[i][i]%MOD;
		for(int i=1;i<=n;i++) if(i!=n-i+1) vall=vall*b[i][n-i+1]%MOD;
		vector<int> v2;
		v2.resize(n+1,1);
		vector<vector<int> > v;
		v.resize(n+1,vector<int>(n+1,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				v[i][j]=b[i][j];
				if(j==i) v[i][j]=1;
				if(j==n-i+1) v[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++) rev[1<<(i-1)]=i;
		for(int i=1;i<=n;i++){
			val[i][0]=1;
			for(int j=1;j<(1<<n);j++){
				int x=rev[j&(-j)];
				val[i][j]=val[i][j^(1<<(x-1))]*v[i][x]%MOD;
			}
		}
		for(int i=0;i<(1<<n);i++){
			int tot=__builtin_popcount(i);
			int cur=vall;
			for(int j=1;j<=n;j++){
				v2[j]=val[j][i^((1<<n)-1)];
				cur=cur*val[j][i]%MOD;
			}
			int now=1;
			for(int j=1;j<=n;j++) now=now*(MOD+1-v2[j])%MOD;
			if((cnt+tot)&1) add(ans,cur*now%MOD);
			else add(ans,-cur*now%MOD);
		}
	}
	cout<<ans<<'\n';
	return 0;
}