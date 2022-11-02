#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, M, S;
    cin >> N >> M >> S;
    S--;
    vector<vector<int>> e(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
    }

    vector<int> from(N, -1), type(N, -1);
    auto dfs = [&](auto &self, int i) -> void {
        for (int j : e[i]) {
            if (j == S) {
                continue;
            }
            if (type[j] != -1 && type[j] != type[i]) {
                vector<int> a, b;

                int k = j;
                while (k != S) {
                    a.push_back(k);
                    k = from[k];
                }
                a.push_back(S);
                reverse(a.begin(), a.end());

                b.push_back(j);
                k = i;
                while (k != S) {
                    b.push_back(k);
                    k = from[k];
                }
                b.push_back(S);
                reverse(b.begin(), b.end());
                cout << "Possible\n";
                cout << a.size() << "\n";
                for (int l : a) {
                    cout << l+1 << " ";
                }
                cout << "\n";
                cout << b.size() << "\n";
                for (int l : b) {
                    cout << l+1 << " ";
                }
                cout << "\n";
                exit(0);
            }
            if (type[j] == -1) {
                from[j] = i;
                type[j] = type[i];
                self(self, j);
            }
        }
    };
    for (int first : e[S]) {
        from[first] = S;
        type[first] = first;
    }
    for (int first : e[S]) {
        dfs(dfs, first);
    }
    cout << "Impossible\n";
}