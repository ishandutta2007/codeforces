#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5;

using project = pair<string, int>;

project readProject() {
    project res;
    cin >> res.first >> res.second;
    return res;
}

int qStart = 0;
vector<string> q;
unordered_map<string, int> maxVersion, minDepth;

void add(project p, int depth) {
    auto it = minDepth.find(p.first);

    if (it == minDepth.end()) {
        maxVersion[p.first] = p.second;
        minDepth[p.first] = depth;
        q.push_back(p.first);
    } else {
        if (it->second == depth) {
            maxVersion[p.first] = max(maxVersion[p.first], p.second);
        }
    }
}

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<project, vector<project>> graph;

    project start;
    forn(i, n) {
        project cur = readProject();
        if (i == 0)
            start = cur;
        int k;
        cin >> k;
        vector<project> edges;
        edges.reserve(k);
        forn(j, k) {
            edges.push_back(readProject());
        }

        graph[cur] = std::move(edges);
    }

    add(start, 1);

    while (qStart < q.size()) {
        string name = q[qStart++];
        project p = {name, maxVersion[name]};
        const auto& edges = graph[p];
        int nextDepth = minDepth[name] + 1;

        for (const auto& to : edges) {
            add(to, nextDepth);
        }
    }

    sort(q.begin() + 1, q.end());
    cout << q.size() - 1 << '\n';
    for (int i = 1; i < q.size(); ++i) {
        string name = q[i];
        cout << name << ' ' << maxVersion[name] << '\n';
    }

    
    return 0;
}