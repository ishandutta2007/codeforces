//#define _GLIBCXX_DEBUG

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include<bitset>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

#define FILENAME "souvenir"

int main(){
    string s = FILENAME;
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    //cout<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock(); 
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    cout.sync_with_stdio(0); 
    cout.precision(5);
    cout << fixed;
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
#ifdef DEBUG
    cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x: a) {
        cin >> x;
    }
    
    vector<int> ml(n);
    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            ml[i] = 0;
        }
        else {
            if(i >= 2 && a[i - 1] > a[i - 2])
                ml[i] = 1 + ml[i - 1];
            else
                ml[i] = 1;
        }
    }
    
    vector<int> mr(n);
    for(int i = n - 1; i >= 0; --i) {
        if(i == n - 1) {
            mr[i] = 0;
        }
        else {
            if(i + 2 <= n - 1 && a[i + 1] < a[i + 2])
                mr[i] = 1 + mr[i + 1];
            else
                mr[i] = 1;
        }
    }
    
    int mx = 1;
    for(int i = 0; i < n; ++i) {
        mx = max(mx, max(ml[i], mr[i]) + 1);
        if(i >= 1 && i + 1 <= n - 1 && a[i - 1] + 2 <= a[i + 1]) {
            mx = max(mx, ml[i] + mr[i] + 1);
        }
    }
    
    cout << mx;
}