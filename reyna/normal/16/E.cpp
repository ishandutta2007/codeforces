//In the name of God
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int Maxn = 18;
long double prob[Maxn][Maxn];
long double dp[(1 << Maxn)][Maxn];
bool did[(1 << Maxn)];
int ones[(1 << Maxn)];
int n;
void rec(int now){
//  cerr << now << endl;
    if(did[now])
        return;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n;j++)
            if(i != j && (now & (1 << i)) && (now & (1 << j))){
                //cerr << i << " " << j << " " << now <<  " "<< rec(now - (1 << j)) << endl;
                rec(now - (1 << j));
                for(int k = 0; k < n;k++){
                    dp[now][k] += (dp[now - (1 << j)][k] * prob[i][j]);
                }
                //cerr << now << " :) " << ret << endl;
            }
    for(int i = 0; i < n;i++)
        dp[now][i] /= (ones[now]*(ones[now]-1))/2;
    did[now] = true;
    return;
}
int main(){
    cin >> n;
    for(int i = 0; i < n;i++)
        for(int j = 0; j < n;j++)
            cin >> prob[i][j];
    for(int i = 0; i < (1<<n);i++){
        int cnt = 0;
        int tmp = i;
        while(tmp){
            cnt += tmp%2;
            tmp/=2;
        }
        ones[i] = cnt;
    }
    for(int i = 0; i < n;i++){
        dp[(1 << i)][i] = 1;
        did[(1<<i)] = true;
    }
    rec((1 << n)-1);
    long double ans = 0;
    for(int i = 0; i < n; i++){
        cout << dp[(1 << n)-1][i] << setprecision(6) << fixed;
        cout << " ";
    }
    return 0;
}