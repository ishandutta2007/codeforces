#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>

using namespace std;
void solve();
void prec();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
#define int li
li dsu[101010];
int get(int a){
    if(a==dsu[a])
        return a;
    return dsu[a]=get(dsu[a]);
}
int cnt[101010];
void unite(int a,int b){
    dsu[get(a)]=get(b);
}
vector<int> v;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        dsu[i]=i;
    }
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        --a,--b;
        unite(a,b);
    }
    for(int i=0;i<n;++i){
        ++cnt[get(i)];
    }
    for(int i=0;i<n;++i){
        if(cnt[i])
            v.pb(cnt[i]);
    }
    if(v.size()==1){
        cout<<1%k;
        return;
    }
    int ans = 1;
    for(int i=0;i<v.size()-2;++i){
        ans*=n;
        ans%=k;
    }
    for(int i=0;i<v.size();++i){
        ans*=v[i];
        ans%=k;
    }
    cout<<ans;
}