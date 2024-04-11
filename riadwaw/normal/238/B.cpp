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
void solve();

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    clock_t start = clock();
#else
#endif
    int t = 1;
    while(t--)
        solve();

#ifdef DEBUG
    cout << "\n\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;
}
pi a[101010];
void solve(){
    int n, h;
    cin >> n >> h;
    for(int i = 0; i < n ;++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    

    
    if(n == 2){
        cout <<"0\n";
        cout << 1<< ' '<<1<<endl;
        return;
    }
    
    int defaultAnswer = a[n - 1].first - a[0].first + a[n-2].first - a[1].first;
    int mn = min(a[0].first + a[1].first + h, a[1].first + a[2].first);
    int mx =max(a[0].first + a[n-1].first + h, a[n -1 ].first + a[n - 2].first);
    
    if(mx - mn > defaultAnswer){
        cout <<defaultAnswer<<endl;
    }
    else{
        cout<<mx - mn << endl;
    }
    for(int i = 0; i < n; ++i){
        if(a[0].second == i && mx - mn <= defaultAnswer)
            cout<<2<<' ';
        else
            cout<<1<<' ';
    }
}