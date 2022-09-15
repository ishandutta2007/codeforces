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
    int n,m;
    vi v;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        if(a<0)
            v.pb(a);
    }
    sort(v.begin(),v.end());
    int sum=0;
    for(int i=0,s=min((int)v.size(),m);i<s;++i)
        sum+=v[i];
    cout<<-sum;
}