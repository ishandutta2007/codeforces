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
    int n,x[1111];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x[i];
    }
    int mx=0;
    for(int i=0;i<n;++i){
        int l=i,r=i;
        while(l && x[l-1]<=x[l])
            --l;
        while(r<n-1 && x[r+1]<=x[r])
            ++r;
        //cout<<l<<' '<<r<<endl;
        mx=max(mx,r-l+1);
    }
    cout<<mx;
}