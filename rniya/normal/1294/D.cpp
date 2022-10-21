#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q,x; cin >> q >> x;
    vector<int> check(MAX,0),cnt(x,0);
    int now=0;
    for (int i=0;i<q;++i){
        int y; cin >> y;
        if (MAX<=cnt[y%x]){cout << now << '\n'; continue;}
        cnt[y%x]=max(now,cnt[y%x]);
        if (cnt[y%x]<=y) y-=(y-cnt[y%x])/x*x;
        else y+=(cnt[y%x]-y)/x*x;
        if (y<cnt[y%x]) y+=x;
        if (y<MAX) check[y]=1;
        cnt[y%x]=y+x;
        while(check[now]) ++now;
        cout << now << '\n';
    }
}