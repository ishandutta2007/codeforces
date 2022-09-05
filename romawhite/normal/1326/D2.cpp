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
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 1007;
const int MOD = 998244353;

string s;
int n;
int v;

int L, R;

int f(int l, int r) {
    if (l > r) return 0;
    int c = min(l, n - 1 - r);
    if (l < n - 1 - r) {
        L = c + r - l + 1;
        R = c;
    } else {
        L = c;
        R = c + r - l + 1;
    }
    if (c > v) return 0;
    return 2 * c + r - l + 1;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // mt19937 rng(47);

    int t;
    cin >> t;
    FOR(tt,0,t) {
        
        cin >> s;

        n = SZ(s);
        v = 0;
        FOR(i,0,n) {
            if (s[i] == s[n - 1 - i])
                ++v;
            else
                break;
        }
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }
        int res = min(2 * v, n);
        if (res == n) {
            cout << s << endl;
            continue;
        }
        int c1 = v;
        int c2 = v;

        FOR(i,0,n) {
            int l = i - d1[i] + 1;
            int r = i + d1[i] - 1;
            int val = f(l, r);
            if (val > res) 
            {
                res = val;
                c1 = L;
                c2 = R;
            }
        }
        FOR(i,0,n) {
            int l = i - d2[i];
            int r = i + d2[i] - 1;
            int val = f(l, r);
            if (val > res) 
            {
                res = val;
                c1 = L;
                c2 = R;
            }
        }
        cout << s.substr(0, c1) << s.substr(n - c2, c2) << endl;
        
    }
    
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}