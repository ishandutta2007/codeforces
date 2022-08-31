#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MXN = 81;
const int MXM = 100005;
int n, m;
pair<int, int> a[MXN];
int memo[MXN][MXM][2];

int solve(int pos, int idx, int inc) {
    if (pos > m) return 0;
    if (idx >= n) return MXM;
    int &r = memo[idx][pos][inc];
    if (r != -1) return r;

    int from = a[idx].first - a[idx].second;
    int to = a[idx].first + a[idx].second;
    
    r = solve(pos, idx + 1, 0);
    if (pos < from) {
        r = min(r, from - pos + solve(to + from - pos + 1, idx, 1));
    } else if (from <= pos && pos <= to) {
        r = min(r, solve(to + 1, idx, 0));
    } else if (to < pos) {
        r = min(r, (inc == 1 ? 1 : (pos - to)) + solve(pos + 1, idx, 1));
    }

    return r;
}

int main() {
    setIO();
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        cin>>a[i].first>>a[i].second;
    }
    sort(a, a+n);
    memset(memo, -1, sizeof(memo));
    cout<<solve(1, 0, 0)<<endl;
    return 0;
}