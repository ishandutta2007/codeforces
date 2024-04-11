#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=1e18;
const int MAX=1e7+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    vector<vector<int>> cnt(MAX);
    for (int i=0;i<n;++i) cnt[a[i]].emplace_back(i+1);
    ll ans=INF,L,R;
    for (int g=1;g<MAX;++g){
        vector<pair<ll,int>> A;
        for (int i=g;i<MAX;i+=g) if (!cnt[i].empty()){
            for (int j=0;j<cnt[i].size();++j){
                if (A.size()<2) A.emplace_back(i,cnt[i][j]);
            }
            if (A.size()==2) break;
        }
        if (A.size()<2) continue;
        if (A[0].first*A[1].first/g<ans){
            ans=A[0].first*A[1].first/g;
            L=A[0].second; R=A[1].second;
        }
    }
    if (L>R) swap(L,R);
    cout << L << ' ' << R << '\n';
}