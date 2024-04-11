#include <iostream>

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < n; ++i)

struct query{ 
    int l, r; ll d;
}q[100010];

ll num[100010], kai[100010];
int n, m, k;

int main(){
    cin >> n >> m >> k;
    rep(i, n){
	ll a;
	cin >> a;
	num[i] += a;
	num[i + 1] -= a;
    }
    rep(i, m) cin >> q[i].l >> q[i].r >> q[i].d;
    rep(i, k){
	int a, b;
	cin >> a >> b;
	--a;
	++kai[a]; --kai[b];
    }
    rep(i, m) kai[i + 1] += kai[i];
    rep(i, m){
	--q[i].l;
	num[q[i].l] += kai[i] * q[i].d;
	num[q[i].r] -= kai[i] * q[i].d;
    }
    rep(i, n){
	num[i + 1] += num[i]; 
    }
    rep(i, n) cout << num[i] << (i == n - 1 ? '\n' : ' ');
    return 0;
}