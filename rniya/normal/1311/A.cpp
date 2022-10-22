#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int a,b,ans; cin >> a >> b;
        if (a==b) ans=0;
        if (a<b&&((b-a)&1)) ans=1;
        if (a<b&&!((b-a)&1)) ans=2;
        if (b<a&&!((a-b)&1)) ans=1;
        if (b<a&&((a-b)&1)) ans=2;
        cout << ans << '\n';
    }
}