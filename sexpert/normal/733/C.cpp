#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    int m;
    cin >> m;
    vector<int> b(m);
    for(auto &x : b)
        cin >> x;
    int p = 0;
    if(accumulate(a.begin(), a.end(), 0LL) != accumulate(b.begin(), b.end(), 0LL)) {
        cout << "NO\n";
        return 0;
    }
    vector<vector<int>> blocks;
    for(int i = 0; i < m; i++) {
        int cur = b[i];
        vector<int> v;
        while(cur > 0) {
            v.push_back(a[p]);
            cur -= a[p++];
        }
        if(cur < 0) {
            cout << "NO\n";
            return 0;
        }
        blocks.push_back(v);
    }
    int st = 0;
    vector<pair<int, char>> ans;
    for(auto bl : blocks) {
        if(bl.size() == 1) {
            st++;
            continue;
        }
        if(*min_element(bl.begin(), bl.end()) == *max_element(bl.begin(), bl.end())) {
            cout << "NO\n";
            return 0;
        }
        int M = *max_element(bl.begin(), bl.end());
        bool done = false;
        int off = 0;
        for(int i = 1; i < bl.size(); i++) {
            if(bl[i] == M && bl[i - 1] != M) {
                for(int j = 0; j < i; j++)
                    ans.push_back({st + i + 1 + (off--), 'L'});
                for(int j = i + 1; j < bl.size(); j++)
                    ans.push_back({st + i + 1 + off, 'R'});
                done = true;
                break;
            }
        }
        if(done) {
            st++;
            continue;
        }
        for(int i = 0; i + 1 < bl.size(); i++) {
            if(bl[i] == M && bl[i + 1] != M) {
                for(int j = i + 1; j < bl.size(); j++)
                    ans.push_back({st + i + 1 + off, 'R'});
                for(int j = 0; j < i; j++)
                    ans.push_back({st + i + 1 + (off--), 'L'});
                done = true;
                break;
            }
        }
        st++;
    }
    cout << "YES\n";
    for(auto p : ans)
        cout << p.first << " " << p.second << '\n';
}