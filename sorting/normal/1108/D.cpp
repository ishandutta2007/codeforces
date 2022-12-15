#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;

int n, a[N], dp[N][3];
string s;
string remap = "GBR";

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    for(int i = 0; i < n; ++i)
        a[i] = ((s[i] == 'R') ? 2 : (s[i] == 'B' ? 1 : 0));

    for(int i = n - 1; i >= 0; --i){
        for(int j = 0; j <= 2; ++j){
            int &ans = dp[i][j];
            ans = n;

            if(a[i] != j)
                ans = dp[i + 1][a[i]];

            for(int k = 0; k < 3; ++k){
                if(k == j) continue;
                check_min(ans, dp[i + 1][k] + 1);
            }
        }
    }   

    pair<int, int> ans{n + 1, -1};
    for(int i = 0; i < 3; ++i)
        check_min(ans, pair{dp[0][i], i});

    cout << ans.first << "\n";

    int i = 0, j = ans.second;
    while(i < n){
        //cout << i << " " << j << " i j" << endl;
        int curr = n + 1;
        if(a[i] != j){
            if(dp[i + 1][a[i]] == dp[i][j]){
                j = a[i];
                ++i;
                continue;
            }
        }

        for(int k = 0; k < 3; ++k){
            if(k == j) continue;
            if(dp[i + 1][k] + 1 == dp[i][j]){
                s[i] = remap[k];
                ++i;
                j = k;
                break;
            }
        }
    }
    cout << s << "\n";
}