#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()  

void solve(){
    int n, s;
    cin >> n >> s;
    int cnt_0;
    if(n % 2 == 0)
        cnt_0 = n / 2 - 1;
    else
        cnt_0 = n / 2;

    cout << s / (n - cnt_0) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 1; i <= t; ++i)
        solve();
}