// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7, Max1=13 * 5 + 10, Max2=14;

int n,k,m, ans=0, ifac[20], cc[Max1][Max2];
vector<int> vec;

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a %mod)
	if(b&1) ans=1ll*ans*a %mod;
    return ans;
}
int C(int n,int k){
    if(n<0 || k<0 || n<k) return 0;
    int ans=1;
    for(int i=0;i<k;i++)
	ans=1ll*ans*(n-i) %mod;
    return 1ll*ans*ifac[k] %mod;
}
void go(int zr=1,int sm=n-k,int cnt=2,int pos=1){
    if(sm<0) return;
    if(pos==k){
	ans= (1ll*ans + 1ll*zr*cc[n-sm][cnt]) %mod;
	return;
    }
    int pt=sz(vec)-1, tot=1;
    while(pt>=0 && tot+vec[pt]<=m){
	tot+=vec[pt];
	pt--;
    }
    ++pt;
    for(int i=0;i<m;i++){
	vec.PB(i+1);
	go(1ll*zr*(sz(vec)-pt+1) %mod, sm-i, cnt, pos+1);
	vec.pop_back();
	tot++;
	while(pt<sz(vec) && tot>m){
	    tot-=vec[pt];
	    pt++;
	}
    }
    vec.PB(m+1);
    go(zr, sm-m, cnt+1, pos+1);
    vec.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin>>n>>k>>m;

    int fc=1;
    for(int i=0;i<20;i++){
	ifac[i]= Pow(fc,mod-2);
	fc=1ll*fc*(i+1) %mod;
    }
    for(int i=0;i<Max1;i++){
	for(int j=0;j<Max2;j++)
	    cc[i][j]= C(n-i+j-1,j-1);
    }
    go();
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")