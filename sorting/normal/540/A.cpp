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

    string s1, s2;
    cin >> s1;
    cin >> s2;

    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans += min(abs(s1[i] - s2[i]), '9' - max(s1[i], s2[i]) + min(s1[i], s2[i]) - '0' + 1);
    }
    cout << ans << "\n";
}