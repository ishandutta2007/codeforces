#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 50;

int n, c;
vector<int> str[N];
map<int, int> mp;

void remove(int l, int r) {
    if(l > r || mp.empty()) return ;
    for(auto it = mp.lower_bound(l); it != mp.end();) {
        if(it -> second > r) break;
//        int nr = it->first;
        if(it -> second < l) mp[l-1] = it->second;
        if(it -> first > r) {
            mp[it->first] = r + 1;
            break;
        }
        it = mp.erase(it);
        if(mp.empty()) break;
    }
//    cout << mp.size() << endl;
//    for(const auto &p : mp) cout << p.first << " " << p.second << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        str[i].resize(k);
        for(int j = 0; j < k; j++) cin >> str[i][j], str[i][j]--;
    }
    mp[c-1] = 0;
    for(int i = 0; i < n - 1; i++) {
        int pos = -1;
        for(int j = 0; j < min(str[i].size(), str[i+1].size()); j++) {
            if(str[i][j] != str[i+1][j]) { pos = j; break; }
        }
        if(pos == -1) {
            if(str[i].size() > str[i+1].size()) return !printf("-1");
        }
        else {
            int x = str[i][pos], y = str[i+1][pos];
            if(x < y) remove(c - y, c - x - 1);
            else {
                remove(0, c - x - 1);
                remove(c - y, c - 1);
            }
        }
    }
    if(mp.empty()) return !printf("-1");
    cout << mp.begin() -> second << endl;
}