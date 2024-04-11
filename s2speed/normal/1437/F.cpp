#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 5020 , md = 998244353;

ll dp[MAX_N][MAX_N] , pd[MAX_N][MAX_N] , f[MAX_N];
vector<ll> a;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
    cin>>n;
    a.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    sort(a.begin() , a.end());
    int x = -1;
    for(int i = 0 ; i < n ; i++){
        while(a[x + 1] * 2 <= a[i]){
            x++;
        }
        f[i] = x;
    }
    for(int i = 0 ; i < n ; i++){
        dp[i][0] = 1;
        pd[i][0] = i + 1;
    }
    for(int j = 1 ; j < n ; j++){
        for(int i = 0 ; i < n ; i++){
            if(f[i] == -1){
                dp[i][j] = 0;
                pd[i][j] = 0;
            } else {
                ll z = dp[i][j - 1];
                z *= (f[i] + 2 - j);
                z %= md;
                dp[i][j] = z + pd[f[i]][j - 1];
                dp[i][j] %= md;
                pd[i][j] = pd[i - 1][j] + dp[i][j];
                pd[i][j] %= md;
            }
        }
    }
    cout<<pd[n - 1][n - 1]<<"\n";
	return 0;
}