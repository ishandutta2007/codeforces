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
//#define int li

void solve(){
    int n,l,a[111];
    cin>>n>>l;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int best=0;
    for(int i=l;i<=100;++i){
        int ans=0;
        for(int j=0;j<n;++j){
            ans+=a[j]/i;
        }
        best=max(best,ans*i);
    }
    cout<<best;
}