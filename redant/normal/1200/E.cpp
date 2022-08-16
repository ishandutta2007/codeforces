#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 2e6;
int f[SZ];

void ff(string &p) {
    int n = p.length();
    f[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && p[i] != p[j])
            j = f[j-1];
        if (p[i] == p[j]) ++j;
        f[i] = j;
    }
}

void merge(string &res, string &s) {
    ff(s);
    int m = res.length();
    int n = s.length();
    int ps = 0;
    for (int i = m-min(m, n); i < m; i++) {
        while (ps > 0 && res[i] != s[ps])
            ps = f[ps-1];
        if (res[i] == s[ps]) ++ps;
    }
    res.append(s.substr(ps));
}

int main() {
    setIO();
    int n; cin >> n;
    string res; cin >> res;
    REP(i, n-1) {
        string s;
        cin >> s;
        merge(res, s);
    }
    cout << res << endl;
    return 0;
}