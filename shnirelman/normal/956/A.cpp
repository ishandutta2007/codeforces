#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<bool> used(n, false);
    vector<vector<int>> r, c;
    for(int i = 0; i < n; i++) if(!used[i]) {
        r.push_back(vector<int>(1, i));
        c.push_back(vector<int>(0));
        for(int j = 0; j < m; j++) if(a[i][j] == '#') {
            c.back().push_back(j);
            for(int k = i + 1; k < n; k++) if(!used[k] && a[k][j] == '#') {
                used[k] = true;
                r.back().push_back(k);
            }
        }
    }

//    for(int i = 0; i < r.size(); i++) {
//        cout << "R : ";
//        for(auto x : r[i])
//            cout << x << ' ';
//        cout << endl;
//        cout << "C : ";
//        for(auto x : c[i])
//            cout << x << ' ';
//        cout << endl << endl;
//    }

    vector<string> b(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            b[i] += '.';

    vector<int> cnt(m, 0);
    for(int i = 0; i < r.size(); i++) {
        for(auto y : c[i]) {
            cnt[y]++;
            if(cnt[y] > 1) {
                cout << "No" << endl;
                return 0;
            }
            for(auto x : r[i]) {

                b[x][y] = '#';
            }
        }
    }

//    for(auto b1 : b)
//        cout << b1 << endl;

    for(int i = 0; i < n; i++) {
        if(b[i] != a[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}