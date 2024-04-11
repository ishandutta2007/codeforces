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

void solve(){
    int n,c[3]={0,0,0};
    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        ++c[x%3];
    }
    cout<<c[0]/2+min(c[1],c[2]);
}