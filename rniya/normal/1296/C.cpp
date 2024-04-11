#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; string S; cin >> n >> S;
        vector<int> sumx(n+1,0),sumy(n+1,0);
        for (int i=0;i<n;++i){
            sumx[i+1]=sumx[i]; sumy[i+1]=sumy[i];
            if (S[i]=='L') --sumx[i+1];
            if (S[i]=='R') ++sumx[i+1];
            if (S[i]=='U') ++sumy[i+1];
            if (S[i]=='D') --sumy[i+1];
        }
        int M=INF,l,r;
        map<pair<int,int>,int> m;
        for (int i=0;i<=n;++i){
            if (m.count({sumx[i],sumy[i]})){
                if (i-m[{sumx[i],sumy[i]}]<M){
                    M=i-m[{sumx[i],sumy[i]}];
                    l=m[{sumx[i],sumy[i]}]+1; r=i;
                }
            }
            m[{sumx[i],sumy[i]}]=i;
        }
        if (M==INF) cout << -1 << '\n';
        else cout << l << ' ' << r << '\n';
    }
}