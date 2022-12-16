// only miss the sun when it starts to snow

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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

int to[maxn], bp[maxn], cnt[maxn], cnt2[maxn], fac[maxn];
int who[maxn], rwho[maxn], n;

void add(int a,int b){
    if((n/a) != (n/b)) cout<<0<<endl, exit(0);
    if(who[a]==0) who[a]=b, cnt2[n/a]--;
    if(rwho[b]==0) rwho[b]=a;
    if(who[a]!=b) cout<<0<<endl, exit(0);
    if(rwho[b]!=a) cout<<0<<endl, exit(0);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    cin>>n;

    fac[0]=1;
    for(int i=1;i<=n;i++){
	to[i]=1;
	fac[i]= 1ll*i*fac[i-1] %mod;
    }
    cnt[1]++;
    for(int i=2;i<=n;i++){
	if(to[i]==1){
	    cnt2[n/i]++;
	    for(int j=i;j<=n;j+=i)
		to[j]*=i, bp[j]=i;
	    if(2*i>n) to[i]=1;
	}
	cnt[to[i]]++;
    }

    int SQ= sqrt(n) +1;
    
    for(int i=1;i<=n;i++){
	int x; cin>>x;
	if(x!=0){
	    if(to[x] != to[i]){
		if(to[i]==1 || to[x]==1) return cout<<0<<endl,0;
		int A=bp[x], B=bp[i];
		if(A>=SQ && B>=SQ && to[x/A]==to[i/B] ) add(A,B);
		else	    return cout<<0<<endl,0;
	    }
	    else if(to[i]!=1){
		if(bp[i]>=SQ) add(bp[i], bp[i]);
	    }
	    cnt[to[i]]--;
	}
    }
    int ans=1;
    for(int i=1;i<=n;i++){
	ans=1ll*ans* fac[cnt[i]] %mod;
    }
    for(int i=2;i<=n;i++){
	ans=1ll*ans* fac[cnt2[i]] %mod;
    }
    
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")