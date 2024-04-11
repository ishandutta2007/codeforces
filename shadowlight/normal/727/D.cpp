#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <int> cnt(6, 0);
    for (int i = 0; i < 6; i++) {
        cin >> cnt[i];
    }
    int n;
    cin >> n;
    vector <string> sizes(6);
    sizes[0] = "S";
    sizes[1] = "M";
    sizes[2] = "L";
    sizes[3] = "XL";
    sizes[4] = "XXL";
    sizes[5] = "XXXL";
    vector <pair <int, int> > var;
    vector <int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.find(',') == std::string::npos) {
            for (int j = 0; j < 6; j++) {
                if (s == sizes[j]) {
                    ans[i] = j;
                    cnt[j]--;
                }
            }
        } else {
            string s1 = s.substr(0, s.find(','));
            for (int j = 0; j < 6; j++) {
                if (s1 == sizes[j]) {
                    var.push_back({j, i});
                }
            }
        }
    }
    sort(var.begin(), var.end());
    for (int i = 0; i < var.size(); i++) {
        int a1 = var[i].first, a2 = a1 + 1, it = var[i].second;
        if (cnt[a1] > 0) {
            cnt[a1]--;
            ans[it] = a1;
        } else {
            cnt[a2]--;
            ans[it] = a2;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (cnt[i] < 0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << sizes[ans[i]] << endl;
    }
}
/*
1 1 1 1 1 1
5
XL,XXL
XL,XXL
S,M
S,M
XXL,XXXL
*/