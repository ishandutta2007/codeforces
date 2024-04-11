#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, D;
vector<pair<int, int>> friends;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> D;

    friends.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> friends[i].first >> friends[i].second;
    }

    sort(friends.begin(), friends.end());

    ll ans = 0;
    ll cur = 0;

    int j = 0;
    for (int i = 0; i < N; i++) {
        while (j < N && friends[j].first < friends[i].first + D) {
            cur += friends[j].second;
            j++;
        }

        ans = max(ans, cur);
        cur -= friends[i].second;
    }

    cout << ans << endl;
}