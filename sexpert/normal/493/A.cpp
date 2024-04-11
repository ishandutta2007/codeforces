#include <bits/stdc++.h>
using namespace std;

map<pair<char, int>, int> fst;
map<pair<char, int>, int> goty;
map<char, string> teams;

int main() {
    cin >> teams['h'] >> teams['a'];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t, num;
        char team, card;
        cin >> t >> team >> num >> card;
        if(fst.count({team, num}))
            continue;
        if(card == 'y') {
            if(goty.count({team, num})) {
                fst[{team, num}] = t;
                continue;
            }
            else
                goty[{team, num}] = 1;
        }
        else
            fst[{team, num}] = t;
    }
    vector<pair<int, pair<char, int>>> v;
    for (auto p : fst)
        v.push_back(make_pair(p.second, p.first));
    sort(v.begin(), v.end());
    for(auto p : v) {
        cout << teams[p.second.first] << " " << p.second.second << " " << p.first << endl;
    }
}