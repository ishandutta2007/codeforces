// Oh damn! Suddenly you're free to fly
// Shayan.P  2020-08-30

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

ll a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> a[i];
    }
    if(n == 1){
	cout << 1 << " " << 1 << endl << -a[0] << endl;
	cout << 1 << " " << 1 << endl << 0 << endl;
	cout << 1 << " " << 1 << endl << 0 << endl;
	return 0;
    }
    cout << 1 << " " << n-1 << endl;
    for(int i = 0; i < n-1; i++){
	ll x = 1ll * (n-1) * (a[i] % n);
	cout << x << " ";
	a[i]+= x;
    }
    cout << endl;

    cout << 2 << " " << n << endl;
    for(int i = 1; i < n; i++){
	ll x = 1ll * (n-1) * (a[i] % n);
	cout << x << " ";
	a[i]+= x;
    }
    cout << endl;

    cout << 1 << " " << n << endl;
    for(int i = 0; i < n; i++){
	cout << -a[i] << " ";
    }
    cout << endl;
    return 0;
}