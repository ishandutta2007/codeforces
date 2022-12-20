// Never let them see you bleed...
// Shayan.P  2020-04-26

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

bool bad[maxn];
int sm[maxn];

void solve(){
    int a, b, q;
    cin >> a >> b >> q;
    int c = a * b;
    for(int i = 0; i < c; i++){
	bad[i] = (i % a % b) != (i % b % a);
	sm[i] = (i == 0 ? 0 : sm[i-1]) + bad[i];
    }
    while(q--){
	ll l, r;
	cin >> l >> r;
	--l;
	ll ans = 0;
	ans+= ((r / c) - (l / c)) * sm[c-1];
	ans+= sm[r % c] - sm[l % c];
	cout << ans << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	solve();
	cout << "\n";
    }
    return 0;
}