#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> moves;
    int tot = 0;
    while(true) {
        vector<int> v;
        for(int i = 0; i + 1 < s.size(); i++) {
            if(s.substr(i, 2) == "RL") {
                v.push_back(i + 1);
                swap(s[i], s[i + 1]);
                tot++;
                i++;
            }
        }
        if(v.empty())
            break;
        moves.push_back(v);
    }
    int mn = (int)moves.size();
    if(k < mn || k > tot) {
        cout << "-1\n";
        return 0;
    }
    int rem = tot;
    for(int i = 0; i < mn; i++) {
        auto v = moves[i];
        if(rem - (int)v.size() >= k - 1) {
            k--;
            rem -= (int)v.size();
            cout << v.size() << " ";
            for(auto x : v)
                cout << x << " ";
            cout << '\n';
            continue;
        }
        int use = k - (rem - (int)v.size());
        k -= use;
        rem -= (int)v.size();
        for(int i = 0; i < use - 1; i++)
            cout << "1 " << v[i] << '\n';
        int oth = v.size() - use + 1;
        cout << oth << " ";
        for(int i = use - 1; i < (int)v.size(); i++)
            cout << v[i] << " ";
        cout << '\n';
    }
}