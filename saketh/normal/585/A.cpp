#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 4040;

int N;
ll doc[MAXN], out[MAXN], conf[MAXN];
bool rem[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> doc[i] >> out[i] >> conf[i];

    vector<int> cured;

    for (int i = 0; i < N; i++) {
        if (rem[i]) continue;

        cured.push_back(i + 1);

        queue<int> del;

        for (int j = i + 1; j < N; j++) {
            if (doc[i] == 0) break;
            if (rem[j]) continue;

            conf[j] -= doc[i];
            doc[i]--;

            if (conf[j] < 0) {
                rem[j] = true;
                del.push(j);
            }
        }

        while (del.size()) {
            int idx = del.front();
            del.pop();

            for (int j = idx + 1; j < N; j++) {
                if (rem[j]) continue;
                conf[j] -= out[idx];
                if (conf[j] < 0) {
                    rem[j] = true;
                    del.push(j);
                }
            }
        }
    }

    cout << cured.size() << "\n";
    for (int v : cured)
        cout << v << " ";
    cout << "\n";
}