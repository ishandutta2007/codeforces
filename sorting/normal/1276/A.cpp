#include <bits/stdc++.h>

using namespace std;

const int k_N = 2e5 + 3;

string s;
int dp[k_N][2][3];
bool rem[k_N][2][3];
string bad[2] = {"one", "two"};

int get_dp(int pos, bool w, int let){
    if(let == 3)
        return k_N;
    if(pos == s.size())
        return 0;

    return dp[pos][w][let];
}

void solve(){
    cin >> s;

    for(int i = (int)s.size() - 1; i >= 0; --i){
        for(int w = 0; w <= 1; ++w){
            for(int let = 0; let <= 2; ++let){
                int &answer = dp[i][w][let];
                answer = get_dp(i + 1, w, let) + 1;

                int other;
                if(let == 0){
                    if(s[i] == bad[0][0])
                        other = get_dp(i + 1, 0, 1);
                    else if(s[i] == bad[1][0])
                        other = get_dp(i + 1, 1, 1);
                    else
                        other = get_dp(i + 1, 0, 0);
                }
                else{
                    if(s[i] == bad[w][let])
                        other = get_dp(i + 1, w, let + 1);
                    else{
                        if(s[i] == bad[!w][0])
                            other = get_dp(i + 1, !w, 1);
                        else if(s[i] == bad[w][0])
                            other = get_dp(i + 1, w, 1);
                        else
                            other = get_dp(i + 1, 0, 0);
                    }
                }

                if(other < answer){
                    answer = other;
                    rem[i][w][let] = false;
                }
                else
                    rem[i][w][let] = true;
            }
        }
    }

    cout << dp[0][0][0] << "\n";
    int i = 0, w = 0, let = 0;
    while(i != (int)s.size()){
        //cout << "\n " <<  i << " " << w << " " << let << " -----" << "\n";
        if(!rem[i][w][let]){
            if(let == 0){
                if(s[i] == bad[0][0]){
                    w = 0;
                    let = 1;
                }
                else if(s[i] == bad[1][0]){
                    w = 1;
                    let = 1;
                }
                else{
                    w = 0;
                    let = 0;
                }
            }
            else{
                if(s[i] == bad[w][let])
                    let++;
                else{
                    if(s[i] == bad[!w][0]){
                        w = !w;
                        let = 1;
                    }
                    else if(s[i] == bad[w][0]){
                        let = 1;
                    }
                    else{
                        w = 0;
                        let = 0;
                    }
                }
            }
        }
        else
            cout << i + 1 << " ";
    
        i++;
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}