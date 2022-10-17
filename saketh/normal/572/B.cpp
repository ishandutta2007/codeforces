#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, S;

map<int, int> buy, sell;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        char type;
        int P, Q;

        cin >> type >> P >> Q;

        if (type == 'B') {
            buy[-P] += Q;
        } else {
            sell[P] += Q;
        }
    }

    vector<string> ans;

    int ct = 0;
    for (auto it = sell.begin(); it != sell.end() && ct < S ; it++, ct++) {
        stringstream ss;
        ss << "S " << it->first << " " << it->second;
        ans.push_back(ss.str());
    }

    reverse(ans.begin(), ans.end());

    ct = 0;
    for (auto it = buy.begin(); it != buy.end() && ct < S ; it++, ct++) {
        stringstream ss;
        ss << "B " << -it->first << " " << it->second;
        ans.push_back(ss.str());
    }

    for (string str : ans)
        cout << str << "\n";
}