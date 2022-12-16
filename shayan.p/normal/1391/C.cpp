// And you curse yourself for things you never done
// Shayan.P  2020-08-09

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

    int n;
    cin >> n;
    int ans = 1;
    for(int i = 1; i <= n; i++)
	ans = 1ll * ans * i % mod;
    int tw = 1;
    for(int i = 0; i < n-1; i++)
	tw = 2ll * tw % mod;
    ans = (ans - tw + mod) % mod;
    return cout << ans << endl, 0;
}