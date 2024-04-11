#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 2e6 + 7;

int a, b, r[N], v;

int main() {
    cin >> a >> b;
    for (int i = 0; i < N; i++)
        r[i] = -1;
    r[a] = 0;
    queue <int> q;
    q.push(a);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        if (v > 0)
        if (r[v - 1] == -1) {
            r[v - 1] = r[v] + 1;
            q.push(v - 1);
        }
        if (v <= 10000)
        if (r[v * 2] == -1) {
            r[v * 2] = r[v] + 1;
            q.push(v * 2);
        }
    }
    cout << r[b];
    return 0;
}