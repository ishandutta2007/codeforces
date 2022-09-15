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


int num[2][200000];

void solve() {
    for(int i = 0; i < 2; ++i) {
        string t;
        cin >> t;
        for(int j = 0; j < t.size(); ++j) {
            num[i][j] = t[t.size() - 1- j] - '0';
        }

        for(int k = 0; k < 170000; ++k) {

            if(num[i][k] >= 1 && num[i][k + 1] == 1) {
                num[i][k] -= 1;
                num[i][k + 1] -= 1;
                num[i][k + 2] += 1;
            }
            else if(num[i][k] == 2) {
                assert(k >= 2);
                int z = k;
                do {

                    num[i][z + 1] += 1;
                    num[i][z] = 0;
                    z -= 2;
                    if(z < 0)
                        break;
                    num[i][z] += 1;

                }
                while(num[i][z] == 2);

            }

        }
    }




    for(int i = 180000; i >= 0; --i) {
        if(num[0][i] != num[1][i])  {
            if(num[0][i] < num[1][i]) {
                cout << '<';
            }
            else
                cout << '>';
            return;
        }
    }
    cout << '=';

}