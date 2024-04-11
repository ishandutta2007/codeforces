#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define sz(x) int((x).size())
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> pii;
typedef vector<int> vi;
// you need a careful DP
// no this is dfs right?
// you need to count edges up from each node
// yeah
// hmm. ok let me read your algorithm

const int MAXN = 200100;
vector<pii> edges[MAXN];

int cnt(int a, int b) {
    int sum = 0;
    repi(i, edges[a]) {
        int dest = i->fi;
        if (dest != b) {
            sum += cnt(dest, a);
            sum += i-> se;
        }
    }
    return sum;
}
int N;
int m = 1 << 30;
int cur;
vi ans;
void dfs(int n, int prv) {
    if (cur < m) {
        m = cur;
        ans.clear();
    }
    if (cur == m) {
        ans.pb(n + 1);
    }
    repi(i, edges[n]) {
        int dest = i->fi;
        if (dest != prv) {
            int chng = i->se ? -1 : +1;
            cur += chng;
            dfs(dest, n);
            cur -= chng;
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i < N; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        edges[a].pb(pii(b, 0));
        edges[b].pb(pii(a, 1));
    }
    cur = cnt(0, -1);
    dfs(0, -1);
    sort(ans.begin(), ans.end());
    printf("%d\n", m);
    for(int i = 0; i < sz(ans); ++i) {
        if (i) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    // yo what's your algorithm??
    // this
    // can you get me sz and repi
}