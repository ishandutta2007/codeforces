#include<bits/stdc++.h>
using namespace std;
int dp[2009][10][10][10];
int a[10009],b[10009];
main(){
    int n;
    cin >> n;
    a[0] = 1; b[0] = 0;
    for(int i= 1; i <= n; i++){
        cin >> a[i]>>b[i];
    }
    dp[0][0][0][0]= 1;
    int ans = 1e9;
    for(int i = 0; i <= n; i++)
        for(int x1 = 0; x1 <= 9; x1 ++)
        {
            for(int x2 = x1; x2 <= 9; x2++){

                for(int x3 = x2; x3 <= 9; x3++){
                        if(!dp[i][x1][x2][x3]) continue;
                        //    cout << i <<" "<<x1 <<" "<<x2<<" "<<x3<<" "<<dp[i][x1][x2][x3]<<endl;
                            int d = a[i+1];
                            for(int B = 1; B < 16; B++){

                                vector<int> v = {x1,x2,x3,b[i]};
                                int x = a[i], hg = 0;
                                int Mi = x, Ma = x;
                                for(int k = 0; k < 4; k++){
                                    if(((1<<k) & B) && v[k] !=0)  Mi = min(Mi, v[k]),
                                        Ma = max(Ma, v[k]), v[k] = 0, hg++;
                                }

                                if(i == n && B != 15) continue;
                                if(i == n && B == 15){
                                    int T = min((abs(x - Ma) + abs(Ma - Mi)), abs(x - Mi)+abs(Ma - Mi));
                                    ans = min(ans, dp[i][x1][x2][x3] + T + hg);
                                }
                                if(i == n) continue;
                                int T = min(abs(x-Ma) + abs(Ma - Mi) + abs(d - Mi),
                                            abs(x-Mi) + abs(Ma - Mi) + abs(d - Ma)) + hg + 1;
                                 //   cout << B <<" "<<Mi <<" "<<Ma <<" "<<x<<" "<<d<<" "<<hg<<" "<<T<<endl;
                                sort(v.begin(),v.end());
                             //   if(v[3] == 1) cout<<"What"<<endl;
                                if(dp[i+1][v[1]][v[2]][v[3]])
                                    dp[i+1][v[1]][v[2]][v[3]]=min(dp[i+1][v[1]][v[2]][v[3]],
                                                                  dp[i][x1][x2][x3] + T);
                                else dp[i+1][v[1]][v[2]][v[3]] = dp[i][x1][x2][x3] + T;

                        }
                    }
                }
            }
    cout<< ans - 1<< endl;
}