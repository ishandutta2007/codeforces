// They can't break me, as long as I know who I am...

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

const int maxn = 21, mmask = 1<<20;

ll a[maxn], sm[mmask];
bool ok[mmask];
int dp[mmask];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> a[i];
    }
    for(int msk = 1; msk < (1<<n); msk++){
	vector<ll> v1, v2, tot;
	int N = __builtin_popcount(msk);
	int N1 = N /2;
	int N2 = N - N1;

	ll S = 0;
	
	for(int i = 0; i < n; i++){
	    if(bit(msk, i)){
		if(sz(v1) == N1)
		    v2.PB(a[i]);
		else
		    v1.PB(a[i]);
		S+= a[i];
	    }
	}
	S += N - 1;
	if(S & 1)
	    continue;
	
	for(int msk2 = 1; msk2 < (1<<N1); msk2++)
	    sm[msk2] = sm[msk2 - (msk2 & -msk2)] + v1[ __builtin_ctz(msk2) ];
	ll st1 = sm[(1<<N1) - 1];
	for(int msk2 = 1; msk2 < (1<<N1) -1; msk2++)
	    tot.PB(st1 - sm[msk2]*2);
	sort(tot.begin(), tot.end());
	
	for(int msk2 = 1; msk2 < (1<<N2); msk2++)
	    sm[msk2] = sm[msk2 - (msk2 & -msk2)] + v2[ __builtin_ctz(msk2) ];
	ll st2 = sm[(1<<N2) - 1];
	for(int msk2 = 0; msk2 < (1<<N2); msk2++){
	    ll num = st2 - sm[msk2] *2;
	    auto it = lower_bound(tot.begin(), tot.end(), -num);
	    if( ( msk2 != 0 && abs( num + st1 ) <= N-1 ) || (msk2 != (1<<N2)-1 && abs( num - st1 ) <= N-1 ) || ( it!=tot.end() && abs( (*it) + num ) <= N-1 ) || ( it!=tot.begin() && abs( (*(--it)) + num ) <= N-1 ) ){
		ok[msk] = 1;
		break;
	    }		
	}
    }

    for(int msk = 1; msk < (1<<n); msk++){
	for(int msk2 = msk; msk2; msk2 = (msk2 - 1) & msk)
	    dp[msk] = max( dp[msk], ok[msk2] + dp[msk ^ msk2] );
    }
    return cout << n - dp[(1<<n)-1] <<'\n', 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")