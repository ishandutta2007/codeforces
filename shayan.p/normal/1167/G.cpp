// They can't break me, as long as I know who I am...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 2e5 + 10, Big = 8010;
const double pi = acos(-1);

ll a[maxn];

double acot(int x){
    if(x == 0)
	return pi/2;
    return atan(1/double(x));
}

bitset<Big> bsl, bsr, tmp;
int ptbs;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    
    int n,d;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
	cin >> a[i];
    for(int i = 0; i < n; i++)
	if(a[i] < Big)
	    bsr[a[i]] = 1, ptbs = i+1;
    ll nw = 0;
    int q; cin >> q;
    int pt = 0;    
    while(q--){
	ll x;
	cin >> x;
	bsl = bsl << min(ll(Big + 1), x - nw);
	bsr = bsr >> min(ll(Big + 1), x - nw);
	nw = x;
	
	while(pt < n && a[pt]+1 <= x){
	    if(x-a[pt]-1 < Big)
		bsl[x-a[pt]-1] = 1;
	    pt++;	    
	}
	ptbs = max(ptbs, pt);
	while(ptbs < n && a[ptbs]-x < Big)
	    bsr[a[ptbs]-x] = 1, ptbs++;
	int dans = Big;

	tmp = bsl & bsr;
	dans = min( dans, int( tmp._Find_first() ));
	tmp = bsl & (bsr << 1);
	dans = min( dans, int( tmp._Find_first() ));
	tmp = (bsl << 1) & bsr;
	dans = min( dans, int( tmp._Find_first() ));

	double ans = 2 * acot(dans);
	if(pt != 0)
	    ans = max(ans, acot(x-a[pt-1]-1) );
	if(pt != n)
	    ans = max(ans, acot(a[pt]-x) );
	
	cout << setprecision(10) << ans << fixed << "\n";
    }
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")