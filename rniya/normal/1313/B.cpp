#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n,x,y; cin >> n >> x >> y;
        int M=min(n,max(1,x+y-n+1)),m=min(n,x+y-1);
        cout << M << ' ' << m << '\n';
    }
}