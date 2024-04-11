#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <complex>
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
typedef double ld;
void solve();

#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    solve();
    return 0;
}
#define int li

vector<pi> v[111];
int fs(int k,int from){
    if(k==1)
        return 0;
    for(int i=0;i<2;++i){
        if(v[k][i].first!=from)
            return v[k][i].second+fs(v[k][i].first,k);
    }
}
void solve(){
    int s=0,n;
    cin>>n;
    
    for(int i=0;i<n;++i){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].pb(pi(b,0));
        v[b].pb(pi(a,c));
        s+=c;
    }
    int ans=v[1][0].second+fs(v[1][0].first,1);
    cout<<min(ans,s-ans);
}