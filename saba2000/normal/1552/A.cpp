#include<bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        string s;
        int n;
        cin >>n;
        cin >> s;
        string t = s;
        sort(t.begin(), t.end());
        
        int ans = 0;
        for(int i =0 ;i < s.size(); i++)
            if(s[i] == t[i]) ans++;
        cout << s.size() - ans<<endl;
    }

}