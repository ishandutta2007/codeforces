#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;

// returns true if a/b < x/y
// runs in log time without overflowing longs
// only works on NON-NEGATIVE numbers
typedef long long int ll;
bool lessThan(ll a, ll b, ll x, ll y) {
    if (a / b != x / y)
        return a / b < x / y;

    if (x % y == 0) return false;
    if (a % b == 0) return true;

    return lessThan(y, x % y, b, a % b);
}

// use this if the fractions can be negative
inline constexpr int signum(ll x) { return (x > 0) - (x < 0); }
bool lessThanWithSigns(ll a, ll b, ll x, ll y) {
    int sign1 = signum(a) * signum(b);
    int sign2 = signum(x) * signum(y);
    
    if (sign1 != sign2) return sign1 < sign2;

    a = abs(a); b = abs(b); x = abs(x); y = abs(y);

    if (sign1 < 0)
        return lessThan(x, y, a, b);
    else 
        return lessThan(a, b, x, y);
}

ll goAC(ll hot, ll cold, ll target) {
		target-=cold;
		hot-=cold;
		if (2*target<=hot) {
			return 2;
		}
		ll ans=target/(2*target-hot);
		ll nTurns1=ans;
		ll nTurns2=nTurns1+1;
		ll n1=hot*(nTurns1)-target*(nTurns1+nTurns1-1);
		ll d1=nTurns1+nTurns1-1;
		ll n2=hot*(nTurns2)-target*(nTurns2+nTurns2-1);
		ll d2=nTurns2+nTurns2-1;
		n2*=-1;
		if (lessThan(n2, d2, n1, d1)) {
			return nTurns2*2-1;
		}
		else {
			return nTurns1*2-1;
		}
}

int main() {
	int T; cin>>T;
	for (int tt=0; tt<T; tt++) {
		ll hot, cold, target; cin>>hot>>cold>>target;
		ll ans=goAC(hot, cold, target);
		cout<<ans<<'\n';
	}
	return 0;
}