#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()  

const int N = 300 + 3;

int n, m, c[N];
array<int, 2> a[N];
bool b[N];

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a, a + m, [](auto l, auto r){
        if(l[0] == r[0])
            return l[1] > r[1];
        return l[0] < r[0];
    });

    fill(b, b + m, false);
    for(int i = 0; i < m; ++i)
        c[a[i][1]] = i;

    ll ans = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < c[i]; ++j)
            ans += b[j];
        b[c[i]] = true;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 1; i <= t; ++i)
        solve();
}