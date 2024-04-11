#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 128;

int N;
int a[MAXN];
int b[MAXN];
int c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
        cin >> a[i];

    for (int i = 0; i < N - 1; i++)
        cin >> b[i];

    for (int i = 0; i < N; i++)
        cin >> c[i];

    vector<int> paths;

    for (int i = 0; i < N; i++) {
        int cost = 0;

        for (int j = 0; j < i; j++)
            cost += a[j];

        cost += c[i];

        for (int j = i; j < N - 1; j++)
            cost += b[j];

        paths.push_back(cost);
    }

    sort(paths.begin(), paths.end());

    cout << paths[0] + paths[1] << "\n";
}