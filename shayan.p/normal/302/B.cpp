// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

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

    int n, m;
    cin >> n >> m;
    ll num = 0;
    vector<ll> v;
    for(int i = 0; i < n; i++){
	int a, b;
	cin >> a >> b;
	num+= 1ll * a * b;
	v.PB(num);
    }
    while(m--){
	ll x;
	cin >> x;
	cout << lower_bound(v.begin(), v.end(), x) - v.begin() + 1 << "\n";
    }
    return 0;
}