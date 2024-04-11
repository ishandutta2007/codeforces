#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2500;

int N;
int value[MAXN];

int targ[MAXN];
int loca[MAXN];

vector<pair<int, int>> pairs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> value[i];

    for (int i = 1; i <= N; i++) {
        cin >> targ[i];
        loca[targ[i]] = i;
    }

    int dist = 0;
    for (int i = 1; i <= N; i++) {
        dist += abs(loca[value[i]] - i);
    }

    cout << dist / 2 << "\n";

    vector<pair<int, int>> res;

    for (int i = 1; i <= N; i++) {
        int v = value[i];
        if (loca[v] >= i) continue;

        int l = i;
        for (int j = i-1; j >= loca[v]; j--) {
            if(loca[value[j]] == j) continue;

            res.emplace_back(j, l);
            swap(value[l], value[j]);
            l = j;
        }
    }

    cout << res.size() << "\n";
    for (auto p : res) cout << p.first << " " << p.second << "\n";
}