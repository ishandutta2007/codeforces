// And you curse yourself for things you never done
// Shayan.P  2020-08-16

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 100;

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	ll k;
	cin >> n >> k;
	int mn = inf, mx = -inf;
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	    mn = min(mn, a[i]);
	    mx = max(mx, a[i]);
	}
	if(k & 1){
	    for(int i = 0; i < n; i++)
		cout << mx - a[i] << " ";
	}
	else{
	    for(int i = 0; i < n; i++)
		cout << a[i] - mn << " ";
	}
	cout << "\n";
    }
    return 0;
}