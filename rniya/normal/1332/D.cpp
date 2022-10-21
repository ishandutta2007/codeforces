#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k; cin >> k;
    cout << 3 << ' ' << 2 << '\n';
    vector<vector<int>> ans(3,vector<int>(2));
    ans[0][0]=(1<<18)-1,ans[0][1]=1<<17;
    ans[1][0]=(1<<17)-1,ans[1][1]=(1<<18)-1;
    ans[2][0]=0,ans[2][1]=k;
    for (int i=0;i<3;++i)
        for (int j=0;j<2;++j)
            cout << ans[i][j] << (j!=1?' ':'\n');
}