#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 3005;

int N;
int x[MAXN], y[MAXN];
int ds[MAXN][MAXN];

bitset<MAXN> val[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    vector<pair<int, int>> all;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        for (int j = 0; j < i; j++) {
            ds[j][i] = (x[i] - x[j]) * (x[i] - x[j])
                     + (y[i] - y[j]) * (y[i] - y[j]);
            all.emplace_back(j, i);
        }
    }

    sort(all.begin(), all.end(), [](pair<int, int> a, pair<int, int> b){
        return ds[a.first][a.second] > ds[b.first][b.second]; });

    for (int p = 0; p < all.size(); p++) {
        int i = all[p].first;
        int j = all[p].second;

        bitset<MAXN> tmp = val[i];
        tmp &= val[j];

        if(tmp.any()) {
            cout << sqrt(ds[i][j])/2 << endl;
            return 0;
        }

        val[i].set(j+1, true);
        val[j].set(i+1, true);
    }
}