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
    int ans=0;
    int n,x[1010];
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>x[i];
    for(int i=0;i<n;++i){
        if(abs(x[i]-x[(i+1)%n])<abs(x[ans]-x[(ans+1)%n]))
            ans=i;
    }
    cout<<(ans+1)<<' '<<((ans+1)%n+1);
}