#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int NICO = 1<<17;
typedef pair<int, int> pii;
vector<pii> ans;

int n;
int deg[NICO], s[NICO], val[NICO];
set<pii> st[NICO];

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        scanf("%d %d", &deg[i], &s[i]);
        st[deg[i]].insert(make_pair(s[i], i));
    }

    while(st[1].size()) {
        //cout << st[1].size() << endl;
        pii tmp = *st[1].begin();
        //cout << tmp.first << " " << tmp.second << endl;

        st[1].erase(tmp);
        int u = tmp.second;
        int x = tmp.first;
        int v = x ^ val[u];
        //cout << v << endl;
        val[v] ^= u;
        //cout << u << " " << v << endl;
        ans.push_back(make_pair(u, v));
        //cout << u << " " << v << endl;
        st[deg[v] - 1].insert(make_pair(s[v], v));
        st[deg[v]].erase(make_pair(s[v], v));
        deg[v] --;
    }

    printf("%d\n", (int)ans.size());
    for(int i=0;i<ans.size();i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

}