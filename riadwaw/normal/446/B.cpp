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
    li n, m, k, p;
    cin >> n >> m >> k >> p;
    vector<vector<li>> a(n, vector<li>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    
    priority_queue<li> q;
    for(int i = 0; i < n; ++i) {
        li s = 0;
        for(int j = 0; j < m; ++j) {
            s += a[i][j];
        }
        q.push(s);
    }
    
    
    vector<li> sumsRows(1);
    sumsRows.reserve(k + 1);
    for(int i = 0; i < k; ++i) {
        li z = q.top();
        q.pop();
        sumsRows.push_back(sumsRows.back() + z);
        q.push(z - m * p);
    }
    
    q = priority_queue<li>();
    
    for(int j = 0; j < m; ++j) {    
        li s = 0;
        for(int i = 0; i < n; ++i) {
            s += a[i][j];
        }
        q.push(s);
    }
    
    
    vector<li> sumsCols(1);
    sumsCols.reserve(k + 1);
    for(int i = 0; i < k; ++i) {
        li z = q.top();
        q.pop();
        sumsCols.push_back(sumsCols.back() + z);
        q.push(z - n * p);
    }
    li mx = -1e18;
    
    for(li i = 0; i <= k; ++i) {
        li cur = sumsRows[i] + sumsCols[k - i] - i * (k - i) * p;
        mx = max(mx, cur);
    }
    
    cout << mx;
}