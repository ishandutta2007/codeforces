#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
#include <list>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define NAME ""
void solve();

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    clock_t start = clock();
#else
#endif

    solve();

#ifdef DEBUG
    cout << "\n\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
}
void solve() {
    int n = 332;
    cout << n << endl;
    cout << 1 <<' '<< 500000 << '\n';
    
    
    int start = 100000;
    for(int size = 330; size > 0; --size){
        cout << start + size <<' '<< size <<'\n';
        start += 2 * size + 1;
    }
    
    //cout <<start<<' ';
    
    cout << 450000 <<' '<< 500000 <<'\n';
}