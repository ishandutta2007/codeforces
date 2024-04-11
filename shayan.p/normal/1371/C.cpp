// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-06

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

bool solve(){
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    ll x = min(abs(a-b), n);
    n-=x;
    if(a > b)
	a-= x;
    else
	b-= x;
    x = min({a, b, n, m});
    a-= x, b-=x, n-=x, m-=x;
    if(m == 0)
	return a + b >= n;
    if(n == 0)
	return min({a, b}) >= m;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    int q;
    cin >> q;
    while(q--){
	cout << (solve() ? "Yes\n" : "No\n");
    }
    return 0;
}