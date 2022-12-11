#include <bits/stdc++.h>
using namespace std;

void init() {
//#if __GLIBCXX__ == 20160609
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    ///freopen(TASKNAME".in", "r", stdin);
    ///freopen(TASKNAME".out", "w", stdout);
#endif
}


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e6 + 34;

int a[N], b[N];
unordered_map <int, int> m;
bool u[N];
vector <int> v;
vector <vector<int> > ans;

int nx(int x) {
    return m[a[x]];
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    sort(b, b + n);

    for (int i = 0; i < n; i++)
        m[b[i]] = i;

    int w;
    for (int i = 0; i < n; i++) {
        if (u[i]) continue;
        w = i;
        u[w] = true;
        v = {w + 1};
        w = nx(w);

        while (!u[w]) {
            v.push_back(w + 1);
            u[w] = true;
            w = nx(w);
        }

        ans.push_back(v);
    }

    cout << ans.size() << "\n";
    for (auto q: ans) {
        cout << q.size() << " ";
        for (int i = 0; i < (int)q.size(); i++)
            cout << q[i] << " ";
        cout << "\n";
    }

    return 0;
}