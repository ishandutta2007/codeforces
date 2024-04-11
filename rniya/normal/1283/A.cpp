#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int h,m; cin >> h >> m;
        cout << (23-h)*60+(60-m) << '\n';
    }
}