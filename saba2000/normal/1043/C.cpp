#include<bits/stdc++.h>
using namespace std;
int ans[1009];

main(){

    string s;
    cin >> s;
    for(int i = 1; i < s.size(); i++){

        if(s[i] == s[i-1]) continue;
        ans[i - 1] = 1;
        string g;
        for(int j = 0; j <= i - 1; j++)
            g+=s[j];
        reverse(g.begin(), g.end());
        for(int j = 0; j <= i - 1; j++)
            s[j] = g[j];
    }
    if(s[0] == 'b') ans[s.size()-1] = 1;
    for(int i = 0; i < s.size(); i++)
        cout<<ans[i] <<" ";
    cout<<endl;

}