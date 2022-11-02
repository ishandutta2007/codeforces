#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
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
ll n, m, k;
ll p[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    F0R(i, m){
        cin >> p[i];
    }
    sort(p, p+m);
    ll yeet = -1; //what you yeet up to
    int cnt = 0;
    F0R(i, m){
        if(yeet >= p[i]) continue;

        ++cnt;
        ll amt = (p[i]-i-1);
        ll ree = k-amt%k;
        yeet = p[i]+ree-1;
        //cout << "after " << p[i] << " yeet is " << yeet << "\n";
    }

    cout << cnt << "\n";

    return 0;
}