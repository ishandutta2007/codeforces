#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <random>
#include <chrono>
#include <cassert>
 
 
using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

typedef vector<int> vi;
 

bool prime[300000];

void go() {
    int n, q; cin >> n >> q;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> divs;
    vector< vector<long long> > vals;
    
    multiset<long long> allv;
    
    for (int i = 1; i < n; i++) {
        if (n % i == 0 && !prime[n/i]) {
            divs.push_back(i);
            vals.push_back(vector<long long>(i));
            for (int j = 0; j < i; j++) {
                for (int pos = j; pos < n; pos += i) vals.back()[j] += a[pos] * 1ll * i;
                //dbg(i, j, vals.back()[j]);
                allv.insert( vals.back()[j] );
            }
        }
    }
    
    cout << *allv.rbegin() << '\n';
    for (; q; q--) {
        int p, x; cin >> p >> x; p--;
        
        for (int i = 0; i < divs.size(); i++) {
            int j = p % divs[i];
            allv.erase( allv.find(vals[i][j]) );
            vals[i][j] -= a[p] * 1ll * divs[i];
        }
        
        a[p] = x;
        for (int i = 0; i < divs.size(); i++) {
            int j = p % divs[i];
            vals[i][j] += a[p] * 1ll * divs[i];
            allv.insert( vals[i][j] );
        }
        
        cout << *allv.rbegin() << '\n';
    }
}

void solve()
{
    prime[0]=prime[1]=1;
    for (int i = 2; i <= 300000; i++) if (!prime[i]) {
        for (int j = i+i; j <= 300000; j+=i) prime[j]=i;
    }
    
    int t;
    for (cin >> t; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}