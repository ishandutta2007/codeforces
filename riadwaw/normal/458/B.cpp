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

bool canBeLast(int v);
bool canBeNotLast(int v);

void my_assert(bool b);

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


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for(int& x:a){
        cin >> x;
    }
    for(int& x:b) {
        cin >> x;
    }

    if(*max_element(all(a)) < *max_element(all(b))) {
        a.swap(b);
    }

    int mx =*max_element(all(a));

    long long sumB = 0;
    for(int x: b) {
        sumB += x;
    }

    bool hasMx = false;

    long long ans = 0;
    for(int x: a) {
        if(!hasMx && x == mx) {
            hasMx = true;
            ans += sumB;
        }
        else {
            ans += min(sumB, x * 1LL);
        }
    }

    cout << ans;

}