/*
ZDRAVSTVUYTE
ESLI VI HOTITE MENYA VZLOMAT'
YA VAM SRAZU SKAZHU
TUT BAGOV NETU
UDACHNOGO VZLOMA
SPASIBO ZA VNIMANIE
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    map <string, set <pair <string, int> > > data;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        string s = s1.substr(0, 3);
        string s3 = s1.substr(0, 2);
        s3 += s2[0];
        data[s].insert({s3, i});
    }
    set <string> used;
    vector <string> ans(n);
    for (auto p = data.begin(); p != data.end(); p++) {
        if ((*p).second.size() > 1) {
            for (auto q = (*p).second.begin(); q != (*p).second.end(); q++) {
                if (used.find((*q).first) != used.end()) {
                    cout << "NO" << endl;
                    return 0;
                } else {
                    used.insert((*q).first);
                    ans[(*q).second] = (*q).first;
                   // cout << (*q).second << " " << (*q).first << endl;
                }
            }
        }
    }
    vector <pair <pair <string, string>, int> > newx;
    for (auto p = data.begin(); p != data.end(); p++) {
        if ((*p).second.size() == 1) {
            auto p1 = *((*p).second.begin());
            newx.push_back({{(*p).first, p1.first}, p1.second});
        }
    }
    vector <int> used1(newx.size(), 0);
    bool fl = 1;
    while (fl) {
        fl = 0;
        for (int i = 0; i < newx.size(); i++) {
            if (used1[i]) continue;
            if (used.find(newx[i].first.first) != used.end()) {
                fl = 1;
                if (used.find(newx[i].first.second) != used.end()) {
                    cout << "NO";
                    return 0;
                }
                used.insert(newx[i].first.second);
                ans[newx[i].second] = newx[i].first.second;
                used1[i] = 1;
            }
        }
    }
    for (int i = 0; i < newx.size(); i++) {
        if (!used1[i]) {
            ans[newx[i].second] = newx[i].first.first;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}