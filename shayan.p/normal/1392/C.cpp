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

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	}
	ll ans = 0;
	for(int i = n-2; i >= 0; i--){
	    if(a[i] > a[i+1])
		ans+= a[i] - a[i+1];
	}
	cout << ans << "\n";
    }
    return 0;
}