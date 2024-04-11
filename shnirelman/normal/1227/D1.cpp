#include <bits/stdc++.h>

#define x first
#define y second

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using li = long long;
using ld = long double;

const int M = 1e9 + 7;
//const li INF = 1e18;
const int INF = 1e9;



int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.rbegin(), b.rend());

    vector<vector<int>> d(n);
//    for(int i = 0; i < n; i++) {
//        map<int, int> c, c1;
//        for(int j = 0; j <= i; j++)
//            c[b[j]]++;
//
//        int l = 0;
//        for(int j = i; j >= 0; j--) {
//            for(int k = 0; k <= i; k++)
//                c1[b[k]]++;
//            for(l = 0; l < n; l++) {
//                c1[a[l]]--;
//                if(a[l] == b[j]) {
//                    d[i][j] = a[l];
//                    break;
//                }
//                if(c1[a[l]] < )
//            }
//        }
//    }

    for(int i = 0; i < n; i++) {
        //cout << endl << i << endl;
        unordered_map<int, int> c;
        for(int j = 0; j <= i; j++)
            if(c.count(b[j]))
                c[b[j]]++;
            else
                c[b[j]] = 1;

//        for(int j = 0; j < n; j++)
//            c1[a[j]]++;
        //cout << i << endl;
        int l = 0;
        for(int kk = 0; kk <= i; kk++) {
            int mn = -1;
            //cout << kk << endl;
            unordered_map<int, int> c1;
            for(int j = l; j < n; j++)
                if(c1.count(a[j]))
                    c1[a[j]]++;
                else
                    c1[a[j]] = 1;

            for(int j = l; j < n; j++) {

//                if(c.count(a[j]) && c1[a[j]] < c[a[j]])
//                    break;
                c1[a[j]]--;
                if((mn == -1 || a[j] < a[mn]) && c[a[j]] > 0) {
                    mn = j;
                }
                if(c.count(a[j]) && c1[a[j]] < c[a[j]])
                    break;

            }

            //cout << mn << endl;

            d[i].push_back(a[mn]);
            c[a[mn]]--;
            l = mn + 1;
        }

//        for(auto d1 : d[i])
//            cout << d1 << ' ';
//        cout << endl;
    }

    cin >> m;

    for(int i = 0; i < m; i++) {
        int k, j;
        cin >> k >> j;
        cout << d[k - 1][j - 1] << endl;
    }
}