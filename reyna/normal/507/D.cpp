//In the name of God
#include <iostream>
using namespace std;
long long n,k,Mod;
long long pw(long long a,long long b,int M){
    if(b < 1)
        return 1;
    return (pw((a * a) % M,b/2,M) * (b % 2?a:1))% M;
}
const int Maxn = 1e3 + 1e2;
const int MaxK = 123;
long long Md[Maxn][MaxK];
long long dp[MaxK];
int main(){
    cin >> n >> k >> Mod;
    for(int i = 0; i < 10;i++){
        Md[1][i % k]++;
    }
    if(n == 1){
        cout << (Md[1][0]-1+10*Mod)%Mod << endl;
        return 0;
    }
    long long ans = 0;
    ans += ((Md[1][0]-1) * ((pw(10,n-2,Mod) * 9) % Mod)) % Mod;
    for(int i = 2; i <= n;i++){
        for(int j = 0;j < k;j++){
            for(int r = 0; r < 10;r++){
                if(i == n && !r)
                    continue;
                long long ModTen = (pw(10,i-1,k) * r)%k;
                long long now = ((j - ModTen) + 100 * k) % k;
                if(now)
                    Md[i][j] += Md[i-1][now];
                else
                    Md[i][j] += 1;
                Md[i][j] %= Mod;
            }
        }
        if(i != n)
            ans += ((Md[i][0]-1) * ((pw(10,n-i-1,Mod) * 9) % Mod)) % Mod;
        else
            ans += (Md[i][0]) % Mod;
        ans += Mod * 10;
        ans %= Mod;
    }
    cout << ans << endl;
    return 0;
}