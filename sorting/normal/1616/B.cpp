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

        int ans_idx = 0;
        for(int i = 1; i < n; ++i){
            if(s[i] == s[i - 1]){
                if(ans_idx != 0)
                    ans_idx = i;
                continue;
            }
            if(s[i - 1] < s[i])
                break;
            if((ans_idx + 1) * 2 >= (i + 1)){
                ans_idx = i;
            }
            else
                break;
        }

        string ans = "";
        for(int i = 0; i <= ans_idx; ++i)
            ans += s[i];
        string other = ans;
        reverse(all(other));
        cout << ans << other << "\n";
    }
}