#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);
    
    int N, A, B;
    cin >> N >> A >> B;

    array<vector<int>, 2> members;

    for (int i = 1; i <= N; i++) {
        members[i&1].push_back(i);
    }

    array<vector<pair<int, int>>, 2> seats;

    for (int r = 0; r < A; r++) {
        for (int c = 0; c < B; c++) {
            seats[(r+c)&1].emplace_back(r, c);
        }
    }

    if (seats[0].size() > seats[1].size()) {
        swap(seats[0], seats[1]);
    }

    if (members[0].size() > seats[0].size() ||
        members[1].size() > seats[1].size()) {
        cout << -1 << "\n";
        return 0;
    }

    map<pair<int, int>, int> out;

    for (int p = 0; p < 2; p++) {
        int i = 0;

        for (int m : members[p]) {
            out[seats[p][i++]] = m;
        }
    }

    for (int r = 0; r < A; r++) {
        for (int c = 0; c < B; c++) {
            cout << out[{r, c}] << " ";
        }
        cout << "\n";
    }
}