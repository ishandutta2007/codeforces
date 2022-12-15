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

        int ans = 0;
        for(int i = 0; i < n; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            a += b + c;
            if(a >= 2)
                ++ans;
        }
        cout << ans << "\n";
}