#include <bits/stdc++.h>
using namespace std;

map<string, int> to = {
    {"S", 0},
    {"M", 1},
    {"L", 2},
    {"XL", 3},
    {"XXL", 4},
    {"XXXL", 5}
};
vector<string> sz = {"S", "M", "L", "XL", "XXL", "XXXL"};
vector<int> dupe[5];


bool can;
int cnt[6];
int ans[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 6; i++)
        cin >> cnt[i];
    int n;
    cin >> n;
    can = true;
    for(int i = 0; i < n; i++) {
        bool sin = true;
        string s;
        cin >> s;
        for(auto &c : s) {
            if(c == ',') {
                c = ' ';
                sin = false;
                break;
            }
        }
        if(sin) {
            int x = to[s];
            if(cnt[x] == 0)
                can = false;
            cnt[x]--;
            ans[i] = x;
            continue;
        }
        stringstream ss(s);
        string t;
        ss >> t;
        dupe[to[t]].push_back(i);
    }
    for(int i = 0; i < 5; i++) {
        for(auto x : dupe[i]) {
            if(cnt[i] <= 0 && cnt[i + 1] <= 0)
                can = false;
            if(cnt[i] > 0) {
                cnt[i]--,
                ans[x] = i;
                continue;
            }
            cnt[i + 1]--;
            ans[x] = i + 1;
            continue;
        }
    }
    if(!can) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i = 0; i< n; i++)
        cout << sz[ans[i]] << '\n';
}