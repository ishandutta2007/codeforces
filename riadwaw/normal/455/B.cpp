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





vector<map<char, int>> states(1);


void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int cur = 0;
        for(char c: s) {
            if(states[cur].count(c)) {
                cur = states[cur][c];
            }
            else {
                states[cur][c] = states.size();

                cur = states.size();
                states.emplace_back();
            }
        }
    }

    bool cbl = canBeLast(0);
    bool cbnl = canBeNotLast(0);


    //cout << cbl << ' ' << cbnl << endl;
    bool canWin = 0;
    if(cbl && cbnl) {
        canWin = true;
    }
    else if(!cbl && !cbnl) {
        canWin = false;
    }
    else {
        if(cbl) {
            canWin = (k % 2 == 1);
        }
        else
            canWin = false;
    }

    cout << (canWin ? "First" : "Second");
}

bool canBeLast(int v) {
    if(states[v].size() == 0) {
        return false;
    }
    for(auto x: states[v]) {
        if(!canBeLast(x.second))
            return true;
    }
    return false;
}

bool canBeNotLast(int v) {

    if(states[v].size() == 0) {

        //cout << v << true <<endl;
        return true;
    }
    for(auto x: states[v]) {
        if(!canBeNotLast(x.second)) {
            //cout << v << true <<endl;
            return true;
        }
    }
    //cout << v << false <<endl;
    return false;
}