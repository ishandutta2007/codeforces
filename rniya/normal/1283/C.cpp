#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> f(n);
    for (int i=0;i<n;++i) cin >> f[i],--f[i];
    vector<int> check(n,0);
    for (int i=0;i<n;++i) if (f[i]!=-1) check[f[i]]=1;
    vector<int> nxt0,nxt1;
    for (int i=0;i<n;++i) if (!check[i]){
        if (f[i]!=-1) nxt1.emplace_back(i);
        else nxt0.emplace_back(i);
    }
    for (int i=0;i<n;++i) if (f[i]==-1){
        if (0<nxt0.size()&&nxt0.back()==i){
            if (0<nxt1.size()){
                f[i]=nxt1.back(); nxt1.pop_back();
            } else {
                int tmp=nxt0.back(); nxt0.pop_back();
                f[i]=nxt0.back(); nxt0.pop_back();
                nxt0.emplace_back(tmp);
            }
        } else if (0<nxt0.size()){
            f[i]=nxt0.back(); nxt0.pop_back();
        } else {
            f[i]=nxt1.back(); nxt1.pop_back();
        }
    }
    for (int i=0;i<n;++i) cout << f[i]+1 << (i!=n-1?' ':'\n');
}