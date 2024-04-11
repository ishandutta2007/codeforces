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
void solve(){   
    int ryad[1111];
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
        ryad[i]=1<<30;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        ryad[x]=min(y,ryad[x]);
    }
    int s=0;
    for(int i=1;i<=m;++i){
        s+=ryad[i];
    }
    cout<< min(s,k);
}