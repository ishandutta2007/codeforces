#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string s;

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>s;
        int r = 0;
        for(int i = 0; i < s.size(); ) {
            vector<int> vis(26, false);
            ++r;
            int nw = 0;
            for (; i < s.size(); i++) {
                if (!vis[s[i]-'a'] && nw == 3) break;
                nw += !vis[s[i]-'a'];
                vis[s[i]-'a'] = true;
                // cout << s[i] << nw << " ";
            }
            cout<<"\n";
        }
        cout << r << "\n";
    }
    
    return 0;
}