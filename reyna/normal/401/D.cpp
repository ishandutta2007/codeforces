//In the name of God
#include <iostream>
using namespace std;
const int Maxm = 110;
const int Maxn = 18;
long long dp[(1 << Maxn)][Maxm];
int Mod[Maxn][Maxn];
long long div = 1;
long long f(int n){
    if(!n)
        return 1;
    return f(n-1) * n;
}
int main(){
    string S;
    cin >> S;
    int m;
    cin >> m;
    dp[0][0] = 1;
    int n = S.length();
    for(int i = 0; i < n;i++){
        Mod[i][0] = (S[i]-'0') % m;
        for(int j = 1; j < n;j++){
//          cerr << i << " " << j << " " << Mod[i][j] << endl;
            Mod[i][j] = Mod[i][j-1] * 10;
            Mod[i][j] %= m;
        }
    }
    for(int i = 0; i < 10;i++){
        int cnt = 0;
        for(int j = 0; j < n;j++){
            if(S[j] - '0' == i)
                cnt++;
        }
        div *= f(cnt);
    }
    for(int mask = 1; mask < (1 << n);mask++){
        int num = 0;
        for(int j = 0; j < n;j++)
            if(( mask & (1 << j)))
                num++;
        for(int j = 0; j < n;j++){
            if((mask & (1 << j))){
                if(S[j] - '0' || mask != (1 << n) - 1){
                    for(int k = 0; k < m;k++){
                //      cerr << mask << " " << j << " " << k << " " << num<< endl;
                        dp[mask][k] += dp[mask - (1 << j)][(k-Mod[j][num-1]+m)%m];
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][0]/div << endl;
}