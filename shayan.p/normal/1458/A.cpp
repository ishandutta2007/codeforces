#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 2e5 + 10;

ll a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n, m;
    cin >> n >> m;
    ll fx = 0;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	fx = __gcd(fx, abs(a[i]-a[0]));
    }
    for(int i = 0; i < m; i++){
	cin >> b[i];
	cout << __gcd(fx, a[0] + b[i]) << " ";
    }
    return cout << endl, 0;
}