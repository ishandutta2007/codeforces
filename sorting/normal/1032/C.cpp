#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 3;

int n;
int a[k_N];

bool dp[k_N][5 + 3];
int nxt[k_N][5 + 3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = n; i >= 0; --i){
        for(int pr = 1; pr <= 5; ++pr){
            if(i == n){
                dp[i][pr] = true;
                continue;
            }

            dp[i][pr] = false;

            for(int f = 1; f <= 5; ++f){
                if(dp[i + 1][f]){
                    if(i == 0 || (a[i] > a[i - 1] && f > pr) || (a[i] < a[i - 1] && f < pr) || (a[i] == a[i - 1] && f != pr)){
                        dp[i][pr] = true;
                        nxt[i][pr] = f;
                        break;
                    }
                }
            }
        }
    }

    if(!dp[0][1]){
        cout << "-1\n";
        return 0;
    }

    int i = 0, pr = 1;
    while(i != n){
        cout << nxt[i][pr] << " ";
        pr = nxt[i][pr];
        i++;
    }
    cout << "\n";
}