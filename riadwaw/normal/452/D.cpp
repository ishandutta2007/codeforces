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
#include <bitset>
#include <map>
#include <cassert>
#include <memory.h>
#include <limits>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

double dist(pi l, pi r);

#define FILENAME "souvenir"

int main(){
    string s = FILENAME;
#ifdef DEBUG
    freopen("/Users/RiaD/Contests/Contests/input", "r", stdin);
    //freopen("output", "w", stdout);
    //cout<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock(); 
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    cout.sync_with_stdio(0); 
    cout.precision(20);
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
    int k, n[3], t[3];
    cin >> k;
    for(int i = 0; i < 3; ++i) {
        cin >> n[i];
    }
    for(int i = 0; i < 3; ++i) {
        cin >> t[i];
    }
    priority_queue<int, vector<int>, std::greater<int>> pq[3];

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < n[i]; ++j) {
            pq[i].push(0);
        }
    }

    int ans = 0;

    for(int it = 0; it < k; ++it) {
        int timeToStart = max(pq[0].top(), max(pq[1].top() - t[0], pq[2].top() - t[0] - t[1]));

        //cout << timeToStart << endl;
        pq[0].pop();
        pq[0].push(timeToStart + t[0]);

        pq[1].pop();
        pq[1].push(timeToStart + t[0] + t[1]);

        pq[2].pop();
        pq[2].push(timeToStart + t[0] + t[1] + t[2]);

        ans = timeToStart + t[0] + t[1] + t[2];
    }

    cout << ans;
}