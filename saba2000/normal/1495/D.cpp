#include<bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int f[409][409];
int d[409][409];
vector<int> v[409];
main(){
    int n, m;
    cin>> n>> m;
    for(int i= 1; i<= n; i++){
        for(int  j =1; j <= n; j++){
            d[i][j]  = m+1;
            if(i == j) d[i][j] = 0;
        }
    }
    for(int i = 1; i <= m; i++){
        int a,b;
        cin>>a>>b;
        d[a][b] = 1;
        v[a].push_back(b);
        v[b].push_back(a);
        d[b][a] = 1;
    }
    for(int i = 1 ;i <= n; i++){
        for(int  j= 1; j <= n; j++){
            for(int  k =1; k <= n; k++){
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int ok = 1;
            int S = 0;
            for(int k = 1; k <= n; k++){

                if(d[k][i] + d[k][j] == d[i][j]) S++;
            }

            if(S != d[i][j] + 1) {cout<<0<<" "; continue;}
            long long ans =  1;
            for(int k = 1; k <= n; k++){
                if(d[k][i] + d[k][j] == d[i][j]) continue;
                long long num = 0;
                for(int y : v[k]){
                    if(d[y][i] == d[k][i] -1 && d[y][j] == d[k][j] - 1) num++;
                }
                ans = ans * num% mod;
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}