#include<bits/stdc++.h>
using namespace std;
main(){
    long long x,y,n;
    string s;
    cin >> n>>x>> y;
    cin >> s;
    string t = "";
    for(long long i = 0; i < s.size(); i++){
        if (i && s[i] == s[i-1]) continue;
        t += s[i];
    }
    long long Z = 0 ;
    if(t[0] == '0') Z = (t.size() + 1)/2;
    else Z = t.size()/2;
    long long ans = Z * y;
    for(long long i =0 ; i < Z; i++){
        ans = min(ans, (Z - i)*y + i*x);
    }
    cout << ans << endl;
}