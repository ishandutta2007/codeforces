#include <iostream>
#include <cstdio>
#include <set>
#include <map>
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
int d[1000];
int s[1000];
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> d[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    li time = 0;
    li have = 0;
    
    int mx = 0;
    for(size_t i = 0; i < n; ++i){
        have += s[i];
        mx = max(mx, s[i]);
        if(have < d[i]){
            li add = (d[i] - have + mx - 1) / mx;
            time += add * k;
            have += add * mx;
        }
        have -= d[i];
        time += d[i];
        
    }
    
    cout << time;
}