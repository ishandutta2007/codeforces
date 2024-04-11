#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long li;
typedef pair<li, li> pli;
typedef long double ld;
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}

void solve(){
    int n,k,c,l=0,r=0;
    cin>>n>>k>>c;
    for(int i=0;i<c;++i){
        int t;
        cin>>t;
        ++r;
        r+=(t-l-1)/k;
        l=t;
    }
    r+=(n-l)/k;
    cout<<r;
}