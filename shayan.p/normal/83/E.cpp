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

const int maxn=2e5+10, Lg=21, Lg2=(1<<Lg) + 10, inf=1e9;

int a[maxn];
int bst[Lg][Lg2], Lz, n, N;

void add(int x,int val){
    for(int i=0;i<=N;i++){
	int &num=bst[i][x & ((1<<i)-1) ];
	num=max(num, val);
    }
}
int ask(int x){
    int ans=-inf;
    for(int i=0;i<=N;i++){
	ans=max(ans, i + bst[i][x>>(N-i)]);
    }
    return ans;
}
int f(int a,int b){
    int ans=0;
    for(int i=1;i<=N;i++){
	if( (a & ((1<<i)-1)) == (b>>(N-i)) ) ans=i;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    cin>>n;

    for(int i=0;i<n;i++){
	string s; cin>>s;
	N=sz(s);
	for(int j=0;j<N;j++)
	    a[i]+= s[j]=='1' ? (1<<(N-1-j)) : 0;
    }
    for(int i=0;i<Lg;i++)
	for(int j=0;j<Lg2;j++)
	    bst[i][j]=-inf;
    add(a[0],0);
    int tot=f(a[0],a[1]);

    if(n==1) tot=0;
    
    for(int i=1;i<n-1;i++){
	int num=f(a[i],a[i+1]);
	int x= max(tot, ask(a[i+1])+Lz );
	tot+=num, Lz+=num;
	add(a[i], x-Lz);
    }
    int ans= max( tot, Lz + bst[0][0] );

    return cout<<n*N - ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")