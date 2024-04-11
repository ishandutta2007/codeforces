#include <bits/stdc++.h>
using namespace std;
const int MAX=310;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n,x; cin >> n >> x;
        vector<int> check(MAX,0);
        for (int i=0;i<n;++i){
            int a; cin >> a;
            check[a]=1;
        }
        for (int i=1;i<MAX;++i){
            if (!x&&!check[i]){
                cout << i-1 << '\n';
                break;
            }
            if (x&&!check[i]) check[i]=1,--x;
        }
    }
}