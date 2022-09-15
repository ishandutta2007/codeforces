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
    int n;
    pi a[111];
    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        a[i]=pi(x%2,i+1);
    }
    sort(a,a+n);
    if(a[1].first)
        cout<<a[0].second;
    else
        cout<<a[n-1].second;
}