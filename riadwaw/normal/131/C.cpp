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

using namespace std;
void solve();

#define mp make_pair
#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
li c(li n,li k){
    if(k<0 || k>n)
        return 0;
    k=min(k,n-k);
    li ans =1;
    for(int i=1;i<=k;++i){
        ans*=(n+1-i);
        ans/=i;
    }
    return ans;

}
void solve() {
    li n,m,t;
    cin>>n>>m>>t;
    li ans=0;

    for(int i=4;i<t;++i){
        ans+=c(n,i)*c(m,t-i);
    }

    cout<<ans;
}