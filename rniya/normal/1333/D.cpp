#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    string S; cin >> S;
    int Min=0,Max=0;
    vector<vector<int>> cnt;
    while(1){
        int ok=1;
        for (int i=0;i<n-1;++i) if (S[i]=='R'&&S[i+1]=='L'){
            if (ok) cnt.emplace_back();
            cnt[Min].emplace_back(i+1);
            S[i]='L',S[i+1]='R'; ok=0; ++Max,++i;
        }
        if (ok) break;
        ++Min;
    }
    if (k<Min||Max<k){cout << -1 << '\n'; return 0;}
    k-=Min;
    for (int i=0;i<cnt.size();++i){
        int l=0;
        while(k&&l+1<cnt[i].size()){
            cout << 1 << ' ' << cnt[i][l++] << '\n';
            --k;
        }
        int left=(int)cnt[i].size()-l;
        if (!left) continue;
        cout << left;
        for (int j=l;j<cnt[i].size();++j) cout << ' ' << cnt[i][j];
        cout << '\n';
    }
}