//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 1020;
int C[50 * Maxn][Maxn];
const int Mod = 1e9 + 7;
int pri[Maxn * Maxn];
int num[Maxn * Maxn];
int sz;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < 50 * Maxn;i++){
        for(int j = 0; j <= min(i,n);j++){
            if(i == j || !j){
                C[i][j] = 1;
                continue;
            }
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % Mod;
        }
    }
    for(int i = 0; i < n;i++){
        int now;
        cin >> now;
        for(int j = 2; j * j <= now;j++){
            if(now < j)
                break;
            while(now % j == 0){
                int give = sz;
                bool flag = 0;
                for(int i = 0; i < sz;i++)
                    if(j == pri[i]){
                        give = i,flag = 1;
                        break;
                    }
                if(!flag)
                    pri[sz++] = j;
                num[give]++;
                now /= j;
            }
        }
        if(now - 1){
            int give = sz;
            bool flag = 0;
            for(int i = 0; i < sz;i++)
                if(now == pri[i]){
                    give = i,flag = 1;
                    break;
                }
            if(!flag)
                pri[sz++] = now;
            num[give]++;
        }
    }
    long long ans = 1;
    for(int i = 0; i < sz;i++){
        ans *= C[num[i] + n - 1][n-1];
        ans %= Mod;
        ans += Mod;
        ans %= Mod;
    }
    cout << (ans+Mod)%Mod << endl;
    return 0;
}