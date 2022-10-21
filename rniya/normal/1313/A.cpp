#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<vector<int>> v={{1,0,0,1,0,1,1}
                        ,{0,1,0,1,1,0,1}
                        ,{0,0,1,0,1,1,1}};
    int t; cin >> t;
    for (;t--;){
        vector<int> a(3);
        for (int i=0;i<3;++i) cin >> a[i];
        int ans=0;
        for (int mask=0;mask<(1<<7);++mask){
            vector<int> b=a;
            int cnt=0,ok=1;
            for (int i=0;i<7;++i) if (mask&1<<i){
                ++cnt;
                for (int j=0;j<3;++j){
                    b[j]-=v[j][i];
                    if (b[j]<0) ok=0;
                }
            }
            if (ok) ans=max(ans,cnt);
        }
        cout << ans << '\n';
    }
}