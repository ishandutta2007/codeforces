#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<string> s(n);
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    
    map<string, int> mp;
    for(int i = 0; i < n; ++i)
        mp[s[i]]++;
        
    string ans = "";
    string mid = "";
    for(int i = 0; i < n; ++i){
        string rev = s[i];
        reverse(rev.begin(), rev.end());
        if(rev == s[i]){
            int cnt = mp[s[i]];
            mp[s[i]] = 0;
            if(cnt & 1)
                mid = s[i];
            for(int j = 0; j < cnt / 2; ++j)
                ans += s[i];
        }
        else{
            int cnt1 = mp[s[i]];
            int cnt2 = mp[rev];
            mp[s[i]] = 0;
            mp[rev] = 0;
            
            for(int j = 0; j < min(cnt1, cnt2); ++j)
                ans += s[i];
        }
    }
    
    cout << 2 * ans.size() + mid.size() << "\n";
    
    cout << ans << mid;
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}