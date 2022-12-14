#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 2e5 + 5, MOD = 998244353;
int t, n;
string s;

void Enter() {
    cin >> n >> s;
}

long long power(long long x, int k) {
    long long ans = 1;
    while (k) {
        if(k&1) ans = ans*x%MOD;
        x=x*x%MOD;
        k>>=1;
    }
    return ans;
}

void Process() {
    int len = s.length();
    int c_r = 0, c_d = 0;
    int xx = 1, yy = 1;
    for(char c : s) {
        if (c == 'D') ++xx;
        else ++yy;
    }
    if (xx == 1 || yy == 1) {
        cout << n << '\n';
        return;
    }
    xx = yy = 1;
    long long ansx = 0, ansy = 0, tmp = 0, px = 1, py = 1;
    for(char c : s) {
        if (c == 'D') {
            ++xx;
            if (yy == 1) px = xx;
            else tmp += yy - py;
        }
        else {
            ++yy;
            if (xx == 1) py = yy;
            else tmp += xx - px;
        }
    }
    cout << (long long)n * n - (n - 1LL) * (px + py - 2) - tmp << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}