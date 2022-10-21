#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<vector<int>> M(n,vector<int>(m));
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin >> M[i][j];
    vector<vector<int>> L(n,vector<int>(m));
    for (int i=0;i<=n;++i){
        for (int j=0;j<n;++j)
            for (int k=0;k<m;++k)
                L[j][k]=M[j][k];
        string ans1="",ans2="";
        for (int j=0;j<n;++j){
            ans1+='0';
            if (j<i&&L[j][0]==1) ans1.back()='1';
            if (i<=j&&L[j][0]==0) ans1.back()='1';
            if (ans1.back()=='1'){
                for (int k=0;k<m;++k) L[j][k]^=1;
            }
        }
        int ok=1,now=0;
        for (int k=0;k<m;++k){
            ans2+='0';
            int border=0;
            for (int j=1;j<n;++j){
                if (L[j][k]!=L[j-1][k]) ++border;
            }
            if (1<border){ok=0; break;}
            if (L[0][k]>L[n-1][k]) ans2.back()='1';
            if (!border&&L[0][k]==0&&i<n) ans2.back()='1';
            if (!border&&L[n-1][k]==1&&1<i) ans2.back()='1';
            if (ans2.back()=='1'){
                for (int j=0;j<n;++j) L[j][k]^=1;
            }
        }
        if (!ok) continue;
        for (int j=0;j<n;++j){
            for (int k=0;k<m;++k){
                if (L[j][k]<now) ok=0;
                else now=L[j][k];
            }
        }
        if (ok){
            cout << "YES" << '\n';
            cout << ans1 << '\n';
            cout << ans2 << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
}