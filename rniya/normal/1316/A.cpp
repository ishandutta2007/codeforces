#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n,m; cin >> n >> m;
        vector<int> a(n);
        int sum=0;
        for (int i=0;i<n;++i){
            cin >> a[i]; sum+=a[i];
        }
        cout << (m<=sum?m:sum) << '\n';
    }
}