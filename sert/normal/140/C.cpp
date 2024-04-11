#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5 + 34;
const ll INF = 1e9;

int n, x;
map <int, int> m;
vector <pair<int, pair<int, int> > > ans;
pair<int, int> a, b, c;
priority_queue <pair<int, int> > q;

int main() {

    srand(3431);

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        m[x]++;
    }

    for (map<int,int> :: iterator it = m.begin(); it != m.end(); it++)
        q.push(make_pair(it->second, it->first));

    while (q.size() >= 3) {
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        c = q.top(); q.pop();
        if (a.first > 1) q.push(make_pair(a.first - 1, a.second));
        if (b.first > 1) q.push(make_pair(b.first - 1, b.second));
        if (c.first > 1) q.push(make_pair(c.first - 1, c.second));
        if (a.second < b.second) swap(a, b);
        if (a.second < c.second) swap(a, c);
        if (b.second < c.second) swap(b, c);
        ans.push_back(make_pair(a.second, make_pair(b.second, c.second)));
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
    }

    //while(true);
}