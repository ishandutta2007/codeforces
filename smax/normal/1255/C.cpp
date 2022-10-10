#include <bits/stdc++.h>
using namespace std;

struct Q {
    int a, b, c;
};

int cnt[100001] = {};
Q q[100000];
vector<int> queryID[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n-2; i++) {
        cin >> q[i].a >> q[i].b >> q[i].c;
        cnt[q[i].a]++;
        cnt[q[i].b]++;
        cnt[q[i].c]++;
        queryID[q[i].a].push_back(i);
        queryID[q[i].b].push_back(i);
        queryID[q[i].c].push_back(i);
    }

    int prev1, prev2;
    for (int i=1; i<=n; i++)
        if (cnt[i] == 1) {
            prev1 = i;
            break;
        }

    cout << prev1 << " ";
    int prevQuery = queryID[prev1][0];
    if (cnt[q[prevQuery].a] == 2)
        prev2 = q[prevQuery].a, prev1 = (q[prevQuery].b == prev1 ? q[prevQuery].c : q[prevQuery].b);
    else if (cnt[q[prevQuery].b] == 2)
        prev2 = q[prevQuery].b, prev1 = (q[prevQuery].a == prev1 ? q[prevQuery].c : q[prevQuery].a);
    else
        prev2 = q[prevQuery].c, prev1 = (q[prevQuery].a == prev1 ? q[prevQuery].b : q[prevQuery].a);

    swap(prev1, prev2);
    cout << prev1 << " " << prev2 << " ";
    while (cnt[prev2] > 1) {
        int nextQuery;
        for (int i : queryID[prev1])
            for (int j : queryID[prev2])
                if (i == j && i != prevQuery)
                    nextQuery = i;

        if (prev1 == q[nextQuery].a) {
            prev1 = (q[nextQuery].b == prev2 ? q[nextQuery].c : q[nextQuery].b);
            cout << prev1 << " ";
        } else if (prev1 == q[nextQuery].b) {
            prev1 = (q[nextQuery].a == prev2 ? q[nextQuery].c : q[nextQuery].a);
            cout << prev1 << " ";
        } else {
            prev1 = (q[nextQuery].a == prev2 ? q[nextQuery].b : q[nextQuery].a);
            cout << prev1 << " ";
        }

        prevQuery = nextQuery;
        swap(prev1, prev2);
    }
    cout << "\n";

    return 0;
}