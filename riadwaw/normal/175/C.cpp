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
#include <sstream>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
struct figure{
    int cnt;
    li cost;
    bool operator < (const figure& b) const {
        return cost < b.cost;
    }
};

figure fig[1000];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>fig[i].cnt>>fig[i].cost;
    }
    sort(fig, fig+n);
    int t;
    cin>>t;
    li times[111];
    for(int i=0;i<t;++i){
        cin>>times[i];
    }
    li ans =  0;
    int f = 1;
    li have = 0;
    for(int i=0;i<n;++i){
        if(f == t+1 || (have + fig[i].cnt <= times[f-1])){
            ans += fig[i].cnt * fig[i].cost * f;
            have += fig[i].cnt;
        }
        else{
            li need = times[f-1] - have;
            ans += need * fig[i].cost * f;
            have += need;
            fig[i].cnt -= need;
            ++f;
            --i;
        }
    }
    cout<<ans;
}