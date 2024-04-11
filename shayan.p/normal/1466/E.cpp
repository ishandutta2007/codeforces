#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 5e5 + 10, mod = 1e9 + 7, lg = 66;

int cnt[lg], pw[2*lg];
ll a[maxn];

bitset<maxn> tmp1, tmp2;

int BS[66][(maxn/32) + 10];

ll solve(){
    int n;
    cin >> n;
    int N = (n+31) / 32;
    for(int i = 0; i < lg; i++)
	for(int j = 0; j < N; j++)
	    BS[i][j] = 0;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++){
	cin >> a[i];
	for(int j = 0; j < 60; j++){
	    cnt[j]+= bit(a[i], j);
	    BS[j][i/32]|= bit(a[i], j)<<(i&31);
	}
    }
    ll ans = 0;
    for(int b1 = 0; b1 < 60; b1++){
	for(int b2 = 0; b2 < 60; b2++){
	    int x = 0, y = 0;
	    for(int i = 0; i < N; i++){
		x+= __builtin_popcount(BS[b1][i] & BS[b2][i]);
		y+= __builtin_popcount(BS[b1][i] & (~BS[b2][i]));
	    }
	    ll num = (1ll * cnt[b1] * x * n + 1ll * cnt[b1] * y * cnt[b2]) %mod;
	    ans+= 1ll * pw[b1 + b2] * num %mod;
	    ans%= mod;
	}
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    pw[0] = 1;
    for(int i = 1; i < 2*lg; i++)
	pw[i] = 2ll * pw[i-1] %mod;
    
    int q;
    cin >> q;
    while(q--){
	cout << solve() << "\n";
    }    
}