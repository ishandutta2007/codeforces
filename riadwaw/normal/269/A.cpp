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
    //freopen("output", "w", stdout);
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
struct panel{
    int h, l,r;
    bool operator < (const panel& b) {
        return h < b.h || h == b.h && l < b.l;
    }
};
void solve(){
int n,a ,k;
cin >> n;
int ans = 0;
for(int i = 0; i < n; ++i){
    cin >>k>>a;
    if(a == 1){
        ans = max(ans, k + 1);
    }
    else{
        int cur = k;
        while(a > 1){
            ++cur;
            a = (a + 3)/4;
        }
        ans = max(cur, ans);
    }
    
}
cout << ans;
}

/*
panel p[101010];
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
    }
}*/