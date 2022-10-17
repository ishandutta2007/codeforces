#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1000;

int N;
int part[MAXN];
vector<pair<int, pair<int, int>>> pos;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;
    N *= 2;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            int val;
            cin >> val;

            pos.emplace_back(val, make_pair(i, j));
        }
    }

    memset(part, 0xff, sizeof(part));

    sort(pos.begin(), pos.end());

    for (int i = pos.size() - 1; i >= 0; i--) {
        int u = pos[i].second.first;
        int v = pos[i].second.second;

        if(part[u] != -1 || part[v] != -1) continue;
        
        part[u] = v;
        part[v] = u;
    }

    for (int i = 0; i < N; i++)
        cout << part[i] + 1 << " ";
    cout << endl;
}