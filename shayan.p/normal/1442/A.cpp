// Oh my lord I need you by my side...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

int a[maxn];

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> a[i];
    }
    ll x = a[0];
    a[n] = 0;
    for(int i = 0; i < n; i++){
	a[i] = a[i+1] - a[i];
    }
    for(int i = 0; i < n-1; i++){
	if(a[i] < 0)
	    x+= a[i];
    }
    if(x < 0){
	cout << "NO\n";
	return;
    }
    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	solve();
    }
}