#include<bits/stdc++.h>
using namespace std;
main(){
    int n, m;
    cin >> n >> m;
    vector<int> X, v;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        X.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int x1, x2, y;
        scanf("%d %d %d", &x1, &x2, &y);
        if(x1 == 1) v.push_back(x2);
    }
    X.push_back(1e9);
    sort(X.begin(), X.end());
    int j = 0, ans = n + m;
    sort(v.begin(), v.end());
    for(int i = 0; i < X.size(); i++){
        while(j < v.size() && v[j] < X[i]) j++;
        ans = min(ans, (int)v.size() - j + i);
    }
    cout << ans << endl;
}