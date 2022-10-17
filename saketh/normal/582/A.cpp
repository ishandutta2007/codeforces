#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void remove(set<pair<int, int>> &a, int v) {
    auto it = a.lower_bound({v, -1});
    a.erase(it);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N;
    cin >> N;

    set<pair<int, int>> nums;

    for (int i = 0; i < N * N; i++) {
        int V;
        cin >> V;
        nums.insert({V, i});
    }

    vector<int> res;

    while(res.size() < N) {
        int new_elt = prev(nums.end())->first;
        nums.erase(prev(nums.end()));

        for (int i = 0; i < res.size(); i++) {
            int g = __gcd(res[i], new_elt);
            remove(nums, g);
            remove(nums, g);
        }

        res.push_back(new_elt);
    }

    for (int i = 0; i < N; i++)
        cout << res[i] << " ";
    cout << "\n";
}