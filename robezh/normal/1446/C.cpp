#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 * 30 + 5;

int s = 1;
int n;
int a[N];
int nxt[N][2];
int cnt[N];

void add(int x) {
    int cur = 0;
    for(int i = 29; i >= 0; i--) {
        int &nx = nxt[cur][(x >> i) & 1];
        if(nx == -1) nx = s++;
        cur = nx;
    }
    cnt[cur]++;
}

int calc(int x) {
    if(cnt[x]) return 1;
    if(nxt[x][0] != -1 && nxt[x][1] != -1) return max(calc(nxt[x][0]), calc(nxt[x][1])) + 1;
    if(nxt[x][0] != -1) return calc(nxt[x][0]);
    else return calc(nxt[x][1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(nxt, -1, sizeof(nxt));
    cin >> n;
    rep(i, 0, n) cin >> a[i], add(a[i]);
    cout << n - calc(0) << '\n';
}