#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

const int maxn = 1e5 + 10;

pll A, B;

ll operator * (pll a, pll b){
    return a.F * b.S - a.S * b.F;
}
pll operator - (pll a, pll b){
    return {a.F - b.F, a.S - b.S};
}
pll operator * (pll a, ll k){
    return {a.F * k, a.S * k};
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n;
    cin >> n >> A.F >> A.S >> B.F >> B.S;
    if((A * B) == 0)
	return cout << "NO\n", 0;
    if(A.F < 0)
	A = A * -1;
    if(B.F < 0)
	B = B * -1;
    while(A.F > 0 && B.F > 0){
	if(A.F < B.F)
	    swap(A, B);
	ll k = A.F / B.F;
	A = A - (B * k);	
    }
    // overflow?
    if(B.F == 0)
	swap(A, B);
    ll num = 1ll * abs(A.S) * abs(B.F);
    if(num != n)
	return cout << "NO\n", 0;
    cout << "YES\n";
    for(int x = 0; x < abs(B.F); x++)
	for(int y = 0; y < abs(A.S); y++)
	    cout << x << " " << y << "\n";
    for(int i = num; i < n; i++)
	cout << i << " " << i << "\n";
    return 0;
}