#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define int long long
#define p pair<int, int>
#define endl '\n'
const int INF = 1000000001;

using namespace std;

const int C = 1000000007;

int pow1(int x, int y, int z=C){
    if (y == 0){
        return 1;
    }
    if (y % 2 == 0){
        return pow1(x*x % z, y/2, z);
    }
    return pow1(x, y-1, z)*x % z;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*int n;
    cin >> n;
    vector<int> deg = {1};
    for (int q = 0; q < n; q++){
        deg.push_back(deg.back()*2);
    }
    vector<int> ans(1000);
    for (int q = 0; q < (1 << (3*n)); q++){
        vector<int> norm;
        for (int q1 = 0; q1 < 3*n; q1 += 3){
            norm.push_back((q >> q1) & 7);
        }
        int now = 0;
        for (int q1 = 0; q1 < n; q1++){
            now += norm[q1]*deg[q1];
        }
        ans[now]++;
    }
    for (int q = 0; q < 50; q++){
        cout << ans[q] << endl;
    }*/
    int m;
    cin >> m;
    for (int q = 0; q < m; q++){
        int x;
        cin >> x;
        int ans = (x/4 % C)*((x/4+1) % C) % C*pow1(2, C-2) % C*2;
        if (x % 4 < 2){
            cout << (ans+x/4+1) % C << endl;
        }else{
            cout << (ans+x/4*2+2) % C << endl;
        }
    }
    return 0;
}
/*
1
1
2
2
4
4
6
6
9
9
12
12
16
16
20
20
25
25
30
*/