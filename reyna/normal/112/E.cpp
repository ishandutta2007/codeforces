//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 16;
int dp[(1 << Maxn)][3 * Maxn];
int Tree[8];
int main(){
    int n,m;
    cin >> n >> m;
    if(n > m){
        int a = n;
        n = m;
        m = a;
    }
    if(n == 1){
        int tmp = m - m/3;
        if(m % 3)
            tmp--;
        cout << tmp << endl;
        return 0;
    }
    for(int i = 0; i < (1 << Maxn);i++)
        for(int j = 0; j < 3 * Maxn;j++)
            dp[i][j] = 40;
    int Ans = n * m;
    for(int mask = 0; mask < (1 << n);mask++){
        int cnt = 0;
        int arr[n+1];
        for(int i = 0; i < n;i++)
            arr[i] = 0;
        if(mask % 2){
            cnt++;
            arr[0] = 2;
            arr[1] = 1;
        }
        for(int i = 1;i < n;i++){
            if(mask & (1 << i))
                cnt++,arr[i] = 2,arr[i-1] = max(arr[i-1],1),arr[i+1] = 1;
        }
        int MASK = 0;
        for(int i = n-1 ; i +1 ;--i){
            MASK *= 3;
            MASK += arr[i];
        }
        dp[MASK][0] = cnt;
    }
    Tree[0] = 1;
    for(int i = 1; i <= n;i++)
        Tree[i] = Tree[i-1] * 3;
    for(int lev = 1; lev < m;++lev)
        for(int mask1 = 0; mask1 < Tree[n];mask1++){
            for(int mask2 = 0; mask2 < Tree[n];mask2++){
                bool flag = 1;
                int cnt = 0;
                for(int i = 0; i < n;i++){
                    int f1=0,f2=0;
                    f1 = (mask1 / Tree[i]) % 3;
                    f2 = (mask2 / Tree[i]) % 3;
                    if(f1 != 2 && !f2)
                        flag = 0;
                    if(f2 == 2 && !f1)
                        flag = 0;
                }
                if(!flag)
                    continue;
                for(int i = 1; i < n - 1;i++){
                    int f1 = (mask1 / Tree[i]) % 3;
                    int f2 = (mask2 / Tree[i]) % 3;
                    int f3 = (mask1 / Tree[i-1]) % 3;
                    int f4 = (mask1 / Tree[i+1]) % 3;
                    if(f1 == 1 && f2 != 2 && f3 != 2 && f4 != 2)
                        flag = 0;
                }
                int f1 = (mask1 / Tree[0]) % 3;
                int f2 = (mask2 / Tree[0]) % 3;
                int f3 = (mask1 / Tree[1]) % 3;
                if(f1 == 1 && f2 != 2 && f3 != 2)
                    flag = 0;
                int f4 = (mask1 / Tree[n-1]) % 3;
                int f5 = (mask2 / Tree[n-1]) % 3;
                int f6 = (mask1 / Tree[n-2]) % 3;
                if(f4 == 1 && f5 != 2 && f6 != 2)
                    flag = 0;
                if(!flag)
                    continue;
                for(int i = 0; i < n;i++){
                    int f = (mask1 / Tree[i]) % 3;
                    if(f == 2)
                        cnt++;
                }
                dp[mask1][lev] = min(dp[mask1][lev],cnt + dp[mask2][lev-1]);
            }
        }
    for(int i = 0; i < Tree[n];i++){
        int tmp = i;
        for(int j = 0; j < n;j++){
            if(tmp % 3 == 0){
                tmp = -1;
                break;
            }
            tmp/=3;
        }
        if(tmp + 1){
            Ans = min(Ans,dp[i][m-1]);
        }
    }
    cout << n * m - Ans << endl;
    return 0;
}