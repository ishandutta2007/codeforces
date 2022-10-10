#include <bits/stdc++.h>
using namespace std;

int a[200000], degree[200000] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        cin >> a[i];
        degree[--a[i]]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<n; i++)
        if (degree[i] == 0)
            pq.push(i);

    cout << a[0] + 1 << "\n";

    int i = n - 2;
    while (i >= 0) {
        int u = pq.top();
        pq.pop();

        cout << a[i] + 1 << " " << u + 1 << "\n";
        degree[a[i]]--;
        if (degree[a[i]] == 0)
            pq.push(a[i]);
        i--;
    }

    return 0;
}