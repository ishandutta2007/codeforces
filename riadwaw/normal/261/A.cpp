#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
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
void solve();

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    clock_t start = clock();
#else
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

#ifdef DEBUG
    cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;
}

int q[101010];
int c[101010];

void solve(){
    int n, m;
    cin >> m;
    
    for(int i = 0;  i < m; ++i)
        cin >> q[i];
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> c[i];
    
    sort(q, q+ m);
    
    sort(c, c + n);
    reverse(c, c + n);
    
    int sale = q[0];
    li sum = 0;
    
    for(int i = 0; i < n; ++i){
        if(i % (sale + 2) < sale){
            sum += c[i];
        }
    }
    
    cout << sum;
    
}