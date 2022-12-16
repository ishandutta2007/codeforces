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

const int maxn=26, MASK=1<<25;

int ans[2][maxn], a[2*maxn], sm[MASK];
vector<pii> st[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    for(int q=0;q<2;q++)
	for(int i=0;i<n;i++)
	    cin>>a[q*n+i];
    sort(a, a + 2*n, greater<int>());
    ans[0][0]=a[2*n-1], ans[1][0]=a[2*n-2];

    int N=n-1, SM=0;
    for(int i=0;i<2*N;i++)
	SM+=a[i];
    SM=(SM+1)/2;
    
    for(int msk=0;msk<(1<<N);msk++){
	if(msk!=0) sm[msk]= sm[msk ^ (msk & -msk)] + a[__builtin_ctz(msk)];
	st[__builtin_popcount(msk)].PB({sm[msk],msk});
    }
    for(int i=0;i<=N;i++){
	sort(st[i].begin(), st[i].end() );
    }

    pair<int,pii> ANS={1e9,{-1,-1}};
    
    for(int msk=0;msk<(1<<N);msk++){
	if(msk!=0) sm[msk]= sm[msk ^ (msk & -msk)] + a[N+__builtin_ctz(msk)];
	int bt=N - __builtin_popcount(msk);
	auto it=upper_bound(st[bt].begin(), st[bt].end(), (pii){ SM - sm[msk], -1 } );
	if(it != st[bt].end()) ANS=min(ANS, (pair<int,pii>){ sm[msk] + (it->F), {it->S, msk} } );
    }
    int C0=1, C1=1;
    for(int i=N-1;i>=0;i--){
	if(bit(ANS.S.S,i))
	    ans[0][C0++]=a[i+N];
	else
	    ans[1][C1++]=a[i+N];
    }
    for(int i=N-1;i>=0;i--){
	if(bit(ANS.S.F,i))
	    ans[0][C0++]=a[i];
	else
	    ans[1][C1++]=a[i];
    }
    
    reverse(ans[1],ans[1]+n);

    for(int i=0;i<2;i++)
	for(int j=0;j<n;j++)
	    cout<<ans[i][j]<<" \n"[j==n-1];
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")