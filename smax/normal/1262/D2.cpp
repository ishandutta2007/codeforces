#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int ret[200000], orig[200000];
pair<int, int> a[200000];
pair<pair<int, int>, int> q[200000];
ordered_set st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        orig[i] = a[i].first;
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> q[i].first.first >> q[i].first.second;
        q[i].second = i;
    }

    sort(a, a + n, cmp);
    sort(q, q + m);

    int j = 0;
    for (int i=0; i<n; i++) {
        st.insert(a[i].second);
        while (j < m && q[j].first.first == i + 1) {
            ret[q[j].second] = orig[*st.find_by_order(q[j].first.second - 1)];
            j++;
        }
    }

    for (int i=0; i<m; i++)
        cout << ret[i] << "\n";

    return 0;
}