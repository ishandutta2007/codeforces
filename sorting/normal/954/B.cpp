#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = n;
    for(int i = 0; 2 * i + 1 < n; ++i){
        bool eq = true;
        for(int j = 0; j <= i; ++j)
            if(s[j] != s[i + 1 + j]){
                eq = false;
                break;
            }

        if(eq)
            check_min(ans, 1 + (i + 1) + (n - 2 * (i + 1)));
    }

    cout << ans << "\n";
}