#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#define Fi first
#define Se second
using namespace std;
int f[5009][5009];
int fr[5009];
int Ss[5009];
map<string,int> M;
int F(string x){
    if(M[x]) return M[x];
    int ans = 0;
    for(int i = 0; i < x.size(); i++)
        ans += (1<<((int)x.size()-1-i))*(x[i]-'0');
    M[x] = ans;
    return ans;
}
int w[5009];
main(){
     std::ios::sync_with_stdio(false);
     cin.tie(0);
    int n, m , q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        cin >> w[n-i-1];
    }

    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        fr[F(s)]++;
    }
    for(int j = 0; j < (1<<n); j++)
        for(int i = 0; i <n; i++)
        if((1<<i)&j) Ss[j] += w[i];
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < (1<<n); j++){
            int x = (1<<n)-1-(i^j);
            int s = Ss[j];
            f[i][s] += fr[x];
        }
        for(int k = 1; k <= 100; k++)
            f[i][k] += f[i][k-1];
    }
    while(q--){
        string s;
        cin>>s;
        int k;
        cin >> k;
        cout<<f[F(s)][k]<<endl;
    }
}
//01
//00
//