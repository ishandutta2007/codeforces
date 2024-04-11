#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
ll s[MN];
ll d[MN];
ll psd[MN];
int q;
pll ques[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> s[i];
    }
    sort(s, s+n);
    F0R(i, n-1){
        d[i] = s[i+1]-s[i];
    }
    sort(d, d+n-1);
    /*F0R(i, n-1) cout << d[i] << " ";
    cout << "\n";*/
    psd[0] = d[0];
    FOR(i, 1, n-2){
        psd[i] = psd[i-1]+d[i];
    }
    cin >> q;
    F0R(i, q){
        ll l, r;
        cin >> l >> r;

        ll w = r-l+1;

        ll ree = lower_bound(d, d+n-1, w) - d;
        //cout << ree << " ";
        cout << psd[ree-1]+(n-ree)*w << " ";
    }

    return 0;
}