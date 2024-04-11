#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e6 + 10;

ll a[maxn];

bool solve(){
    int n, k;
    cin >> n >> k;
    --k;
    for(int i = 0; i < n; i++)
	cin >> a[i];
    ll l = a[0], r = a[0];
    for(int i = 1; i < n; i++){
	l = max(l-k, a[i]);
	r = min(r+k, a[i]+k);
	if(l > r)
	    return 0;
    }
    return l == a[n-1];
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	cout << (solve() ? "YES\n" : "NO\n");
    }
}