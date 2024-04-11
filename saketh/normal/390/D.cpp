#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print(pair<int, int> loc) {
    if (loc.first > 1) {
        print({ loc.first - 1, loc.second });
    } else if (loc.second > 1) {
        print( { loc.first, loc.second - 1});
    }

    cout << "(" << loc.first << "," << loc.second << ") ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, M, K;

    cin >> N >> M >> K;

    vector<pair<int, pair<int, int>>> points;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            points.emplace_back( (i-1) + (j-1) + 1, make_pair(i, j));

    sort(points.begin(), points.end());

    int total = 0;
    vector<pair<int, int>> used;

    for (int i = 0; i < K; i++) {
        total += points[i].first;
        used.push_back(points[i].second);
    }

    cout << total << "\n";

    sort(used.begin(), used.end());

    for (int i = used.size() - 1; i >= 0; i--) {
        print(used[i]);
        cout << "\n";
    }
}