#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 1e5 + 5;
int n, res, cnt, cnt2;
map<string, int> M;
pair<int, string> a[N];
pair<string, string> b[N];

void Enter() {
    string s;
    int val;
    cin >> n;
    FOR(i, 1, n) cin >> s >> val, M[s] = max(M[s], val);
}

void Process() {
    for(auto v : M) a[++cnt] = {v.second, v.first};
    if (cnt == 1) {
        cout << 1 << '\n' << a[1].second << ' ' << "pro";
        return;
    }
    sort(a+1, a+cnt+1);
    FOR(i, 1, cnt) {
        int j = i;
        while (j <= cnt && a[i].first == a[j].first) ++j;
        long double max_rate = 1000000.0L * (j-1) / cnt;
        string tmp;
        if (max_rate < 500000) tmp = "noob";
        else if (max_rate < 800000) tmp = "random";
        else if (max_rate < 900000) tmp = "average";
        else if (max_rate < 990000) tmp = "hardcore";
        else tmp = "pro";
        REP(w, i, j) b[++cnt2] = {a[w].second, tmp};
        i = j - 1;
    }
    sort(b+1, b+cnt+1);
    cout<<cnt<<'\n';
    FOR(i, 1, cnt2) cout << b[i].first << ' ' << b[i].second << '\n';
}

int main()
{
    #define file "a"
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    if (fopen(file".inp","r")) {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }
    Enter();
    Process();
}