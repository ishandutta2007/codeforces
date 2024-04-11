#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n,m; cin >> n >> m;
        if (m==2){
            for (int i=0;i<n-1;++i) cout << "BW" << '\n';
            cout << "BB" << '\n';
            continue;
        }
        if (n==2){
            for (int i=0;i<m;++i) cout << 'B';
            cout << '\n';
            for (int i=0;i<m-1;++i) cout << 'W';
            cout << 'B' << '\n';
            continue;
        }
        if (!(n&1)){
            for (int i=0;i<m;++i) cout << 'B';
            cout << '\n';
            --n;
        }
        for (int i=0;i<n/2;++i){
            for (int j=0;j<m;++j) cout << 'B';
            cout << '\n';
            for (int j=0;j<m;++j) cout << 'W';
            cout << '\n';
        }
        cout << "BB";
        for (int i=0;i<m-2;++i) cout << 'W';
        cout << '\n';
    }
}