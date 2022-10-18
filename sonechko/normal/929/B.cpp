#include <bits/stdc++.h>
using namespace std;


int n,m;
string ss[1005];
vector<pair<int,int> > v[1005];
int ans;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        s="#"+s;
        s[4]='#';
        s[9]='#';
        s+="#";
        ss[i]=s;
        for (int j=1;j<=12;++j) if (s[j]=='.') {
            int cur=0;
            if (s[j-1]=='S') ++cur;
            if (s[j+1]=='S') ++cur;
            v[cur].push_back(make_pair(i,j));
        }
        for (int j=1;j<=12;++j) {
            if (s[j]=='S') {
                if (s[j-1]=='P' || s[j-1]=='S') ++ans;
                if (s[j+1]=='P' || s[j+1]=='S') ++ans;
            }
        }
    }
    for (int i=0;i<=2 && m>0;++i) {
        for (int j=0;j<v[i].size() && m>0;++j) {
            int x=v[i][j].first;
            int y=v[i][j].second;
            --m;
            ss[x][y]='x';
            ans+=i;
        }
    }
    cout<<ans<<'\n';
    for (int i=1;i<=n;++i) {
        for (int j=0;j<ss[i].size();++j)
            if (ss[i][j]=='#') ss[i][j]='-';
        for (int j=1;j<=12;++j)
            cout<<ss[i][j];
        cout<<'\n';
    }

}