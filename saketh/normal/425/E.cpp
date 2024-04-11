#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#define MOD 1000000007
using namespace std;

#define MAXN 501

long long pwr[200005];
long long ans[505][505];
long long fnd[505][505];
bool sen[505][505];

long long find(int len, int tot){
    if(sen[len][tot]) return fnd[len][tot];
    sen[len][tot] = true;
    
    long long ans = 0;
    for(int sta = 1; sta <= len; sta++){
        int ins = (len - sta);
        int pas = len * (tot - len);
        ans = (ans + pwr[ins+pas]) % MOD;
    }
    return fnd[len][tot] = ans;
}

int main(){
    memset(sen, 0, sizeof(sen));
    
    pwr[0] = 1;
    for(int i = 1; i<150000; i++)
        pwr[i] = (2 * pwr[i-1]) % MOD;

    ans[0][0] = 1;
    for(int k = 1; k<=MAXN; k++)
        ans[0][k] = 0;
    
    for(int n = 1; n<=MAXN; n++){
        ans[n][0] = 1;
        for(int k = 1; k<=MAXN; k++){
            ans[n][k] = 0;
            for(int e = 1; e<=n; e++){
                long long calc = find(e, n);                
                long long way = (calc * ans[n-e][k-1]) % MOD;
                ans[n][k] = (ans[n][k] + way) % MOD;
            }
       }
    }
    
    int N, K;
    cin >> N >> K;    
    cout << ans[N][K] << endl;
    return 0;
}