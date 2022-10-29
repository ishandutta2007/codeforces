#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_map>
#include <omp.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector <ll> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

unordered_map<int, vi> a; 
set<pair<int, int> > fr; 
vi all; 
int m, k; 

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    cin >> m >> k; 
    for (int i = 0; i < m; i++) {
        int x, y; 
        cin >> x >> y; 
        if (a[x].size() == 0) all.pb(x); 
        if (a[y].size() == 0) all.pb(y); 
        a[x].pb(y); 
        a[y].pb(x); 
        fr.insert(mp(x, y)); 
        fr.insert(mp(y, x)); 
    }

    sort(all.begin(), all.end()); 

    for (int i = 0; i < all.size(); i++) {
        vi ans; 
        for (int j = 0; j < all.size(); j++) {
            if (i == j) continue; 
            int iid = all[i]; 
            if (fr.find(mp(all[i], all[j])) != fr.end()) {
                continue; 
            }
            int cnt = 0; 
            for (int k = 0; k < a[iid].size(); k++) {
                int id = a[iid][k]; 
                if (fr.find(mp(all[j], id)) != fr.end()) {
                    cnt++; 
                }
            }
            if (100 * cnt >= a[iid].size() * k) {
                ans.pb(all[j]); 
            }
        }

        cout << all[i] << ": " << ans.size(); 
        for (int i = 0; i < ans.size(); i++) {
            cout << " " << ans[i]; 
        }
        cout << endl; 
    }

    return 0;
}