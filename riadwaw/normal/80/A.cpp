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
    int ar[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51};
    int n,m;
    cin>>n>>m;
    int i=0;
    while(ar[i]!=n)
        ++i;
    if(ar[i+1]==m)
        cout<<"YES";
    else
        cout<<"NO";
}