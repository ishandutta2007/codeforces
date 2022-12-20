// And you curse yourself for things you never done
// Shayan.P  2020-07-29

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int m, d, w;
	cin >> m >> d >> w;
	w/= __gcd(w, d-1);
	m = min(m, d);
	ll n = (m-1) / w;
	cout << n * m - n * (n+1) / 2 * w << "\n";
    }
    return 0;
}