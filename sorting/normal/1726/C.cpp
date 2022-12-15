#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int cnt = 0, active = 1, ans = 0;
        for(char c: s){
            if(c == '('){
                ++cnt;
                if(cnt >= active){
                    ++ans;
                    ++active;
                }
            }
            else{
                if(cnt < active - 1)
                    --active;
                --cnt;
            }
            // cout << cnt << " " << active << "\n";
        }
        cout << ans << "\n";
    }
}