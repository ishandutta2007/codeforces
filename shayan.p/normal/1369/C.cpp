// Never let them see you bleed...
// Shayan.P  2020-06-30

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

int a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	    cin >> a[i];
	for(int i = 0; i < k; i++)
	    cin >> b[i];
	sort(b, b+k, greater<int>());
	sort(a, a+n);
	ll ans = 0;
	while(k >= 0 && b[k-1] == 1){
	    k--;
	    ans+= a[n-1] * 2;
	    n--;
	}
	for(int i = 0; i < k; i++){
	    ans+= a[--n];
	    --b[i];
	}
	int pt = 0;
	for(int i = 0; i < k; i++){
	    ans+= a[pt];
	    pt+= b[i];	    
	}
	cout << ans << "\n";
    }
    return 0;
}