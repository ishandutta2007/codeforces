#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

bool vis[1000010];
int nxt[1000010];

struct dice {
	mt19937 mt;
	dice() {
		random_device rd;
		mt = mt19937(rd());
	}
	int operator()(int x) { return this->operator()(0, x - 1); }
	int operator()(int x, int y) {
		uniform_int_distribution<int> dist(x, y);
		return dist(mt);
	}
} dc;

vector<int> solve(vector<int> a) {
    int N = a.size();
    rep(i, N) {
            int x = a[i];
            nxt[i] = i - x;
        }
        rep(i, N) vis[i] = false;
        int i = 0, i0 = -1;
        for (;;) {
            if (vis[i]) {
                i0 = i;
                break;
            }
            vis[i] = true;
            i = nxt[i];
        }
        vector<int> ans;
        i = i0;
        for (;;) {
            ans.pb(i);
            i = nxt[i];
            if (i == i0) break;
        }
        return ans;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N; scanf("%d", &N);
        rep(i, N) {
            int x; scanf("%d", &x);
            nxt[i] = i - x;
        }
        rep(i, N) vis[i] = false;
        int i = 0, i0 = -1;
        for (;;) {
            if (vis[i]) {
                i0 = i;
                break;
            }
            vis[i] = true;
            i = nxt[i];
        }
        vector<int> ans;
        i = i0;
        for (;;) {
            ans.pb(i);
            i = nxt[i];
            if (i == i0) break;
        }
        int M = ans.size();
        printf("%d\n", M);
        rep(j, M) printf("%d%c", ans[j] + 1, j + 1 < M ? ' ' : '\n');
    }
}