#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 150007;
const int MOD = 998244353;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
    // mt19937 rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    int n;
    cin >> n;
    vector<PII> A(n);
    FOR(i,0,n) {
        cin >> A[i].first;
        A[i].second = i;
    }

    set<PII> S;
    multiset<int> Q;

    int res = A[0].first;
    int cnt = 0;

    sort(ALL(A));

    FOR(i,0,n) {
        int l = A[i].second;
        int r = A[i].second;

        auto it = S.lower_bound(MP(l, l));
        if (it != S.end() && it->first == l + 1) {
            r = it->second;
            int len = it->second - it->first + 1;
            Q.erase(Q.find(len));
            S.erase(it);
            it = S.lower_bound(MP(l, l));
        }

        if (it != S.begin()) {
            it --;
            if (it->second == l - 1) {
                l = it->first;
                int len = it->second - it->first + 1;
                Q.erase(Q.find(len));
                S.erase(it);
            }
        }

        Q.insert(r - l + 1);
        S.insert(MP(l, r));

        int ncnt = S.size();

        if ((i + 1 == n || A[i + 1].first > A[i].first) && *Q.begin() == *Q.rbegin() && ncnt > cnt) {
            cnt = ncnt;
            res = A[i].first + 1;
        }

        // cout << A[i].second << ' ' << l << ' ' << r << endl;

        // cout << i << ' ' << ncnt << ' ' << *Q.begin() << ' ' << *Q.rbegin() << endl;
    }  

    cout << res << endl;

	return 0;
}