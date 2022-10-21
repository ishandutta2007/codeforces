#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int s; cin >> s;
        int ans=0;
        while(s>9){
            ans+=s/10*10;
            s=s%10+s/10;
        }
        cout << ans+s << '\n';
    }
}