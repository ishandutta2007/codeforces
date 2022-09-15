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
#include <cstdlib>
#include <cassert>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

void solve(){
    li n,a,d;
    cin>>n>>a>>d;
    double last = 0;
    for(int i=0;i<n;++i){
        li t,v;
        cin>>t>>v;
        double tt = sqrt(2 * d/ double(a));
        if(tt*a<=v){
            last = max(t+tt,last);
        }
        else{
            double firstt = v/double(a);
            double S = firstt * v/2 ; 
            
            last = max(last,t+firstt + (d - S)/(double)v);
        }
        
        printf("%.10lf\n", last);
    }
}