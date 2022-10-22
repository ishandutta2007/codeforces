#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n,m; cin >> n >> m;
        vector<int> a(n),p(m);
        for (int i=0;i<n;++i) cin >> a[i];
        for (int i=0;i<m;++i) cin >> p[i],--p[i];
        sort(p.begin(),p.end());
        int s=p[0];
        for (int i=1;i<m;++i){
            if (i&&p[i-1]+1!=p[i]){
                sort(a.begin()+s,a.begin()+p[i-1]+2);
                s=p[i];
            }
        }
        sort(a.begin()+s,a.begin()+p[m-1]+2);
        int ok=1;
        for (int i=0;i<n-1;++i){
            if (a[i+1]<a[i]) ok=0;
        }
        cout << (ok?"YES":"NO") << '\n';
    }
}