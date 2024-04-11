#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

int N, M;
int f[MAXN];
vector<int> finv[MAXN];

int a[MAXN];
int b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> f[i];
        finv[f[i]].push_back(i);
    }

    bool ambig = false;

    for (int i = 1; i <= M; i++) {
        cin >> b[i];

        if (finv[b[i]].size() == 0) {
            cout << "Impossible\n";
            return 0;
        }

        else if (finv[b[i]].size() > 1) {
            ambig = true;
        }

        else a[i] = finv[b[i]].front();
    }

    if (ambig) {
        cout << "Ambiguity\n";
        return 0;
    }

    cout << "Possible\n";
    for (int i = 1; i <= M; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}