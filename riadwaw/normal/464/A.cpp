/**
* BE CAREFUL!! I have define int li
*/

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
#include <numeric>
using namespace std;

int timer;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

void prec();

li det(vector<vector<li>> vector);

#define FILENAME "souvenir"

int main(){
    string s = FILENAME;
#ifdef DEBUG
    freopen("/Users/RiaD/Contests/Contests/input", "r", stdin);
    //freopen("/Users/RiaD/Contests/Contests/output", "w", stdout);
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
    //rprec();
    int t = 1;
    //cin >> t;
    while (t--) {
        ++timer;
        solve();
    }
#ifdef DEBUG
    //cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}
string s;

bool ok(int x) {
    if(x >= 1 && s[x - 1] == s[x]) {
        return false;
    }
    if(x >= 2 && s[x - 2] == s[x]) {
        return false;
    }
    return true;
}

void solve() {
    int n, p;
    cin >> n >> p;
    cin >> s;

    int foundIndex = -1;
    for(int i = s.size() - 1; i >= 0; --i) {
        do {
            ++s[i];
        }
        while(!ok(i) && s[i] <= 'a' + p - 1);
        if(s[i] <= 'a' + p - 1) {
            foundIndex = i;
            break;
        }
    }
    if(foundIndex == -1) {
        cout << "NO";
        return;
    }
    for(int i = foundIndex + 1; i < s.size(); ++i) {
        s[i] = 'a';
        while(!ok(i))
            ++s[i];
    }
    cout << s;
}