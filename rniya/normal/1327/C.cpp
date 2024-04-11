#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;
    vector<int> sx(k),sy(k),fx(k),fy(k);
    for (int i=0;i<k;++i) cin >> sx[i] >> sy[i];
    for (int i=0;i<k;++i) cin >> fx[i] >> fy[i];
    string ans="";
    for (int i=0;i<n-1;++i) ans+='U';
    for (int i=0;i<m-1;++i) ans+='L';
    for (int i=0;i<m-1;++i) ans+='R';
    for (int i=0;i<n-1;++i){
        ans+='D';
        for (int j=0;j<m-1;++j) ans+=(i&1?'R':'L');
    }
    cout << ans.size() << '\n';
    cout << ans << '\n';
}