#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 32 + 13;
const int K = 513;
const int M = 1e9 + 7;
const int LOGN = 20;
const int A = 26;

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

//    vector<vector<int>> poss(3), post(3);
    vector<vector<int>> pos(3);
    string s1 = "", t1 = "";
    for(int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
//        poss[s[i] - 'a'].push_back(i);
//        post[t[i] - 'a'].push_back(i);
//        if(s[i] != 'b')
//            s1 += s[i];
//        if(t[i] != 'b')
//            t1 += t[i];
    }

//    cout << (s1 == t1 ? "YES\n" : "NO\n");
//
//    for(int i = 0; i < 3; i++) {
//        if(poss[i].size() != post[i].size()) {
//            cout << "NO\n";
//            return;
//        }
//    }

//    for(int i = 0; i < poss[0].size(); i++) {
//        if(poss[0][i] > post[0][i]) {
//            cout << "NO\n";
//            return;
//        }
//    }
//
//    for(int i = 0; i < poss[2].size(); i++) {
//        if(poss[2][i] > post[2][i]) {
//            cout << "NO\n";
//            return;
//        }
//    }

//    for(int i = 0; i < 3; i++) {
//        cout << i << " : ";
//        for(int j : pos[i])
//            cout << j << ' ';
//        cout << endl;
//    }


    vector<int> ind(3, 0);
    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << ind[0] << ' ' << ind[1] << ' ' << ind[2] << endl;
        int mn = -1;
        for(int j = 0; j < 3; j++) {
            if(ind[j] < pos[j].size() && (mn == -1 || pos[j][ind[j]] < pos[mn][ind[mn]]))
                mn = j;
        }

        int x = t[i] - 'a';

        if(x == mn) {
            ind[mn]++;
            continue;
        }

        if(x == 0 && mn != 0 || x == 1 && mn == 2 || x == 2 && mn == 0) {
            cout << "NO\n";
            return;
        }

//        if(x == 0 && mn == 1 && ind[0] < pos[0].size() && (ind[2] == pos[2].size() || pos[2][ind[2]] > pos[0][ind[0]])) {
//            ind[0]++;
//            continue;
//        }

        if(x == 1 && mn == 0 && ind[1] < pos[1].size() && (ind[2] == pos[2].size() || pos[2][ind[2]] > pos[1][ind[1]])) {
            ind[1]++;
            continue;
        }

        if(x == 2 && mn == 1 && ind[2] < pos[2].size() && (ind[0] == pos[0].size() || pos[0][ind[0]] > pos[2][ind[2]])) {
            ind[2]++;
            continue;
        }

        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}