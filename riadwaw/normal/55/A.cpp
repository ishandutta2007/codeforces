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
    set<pi> sost;
    bool a[1111];
    
    int n;
    cin>>n;
    int k=1%n,m=0;
    while(true){
        if(sost.find(mp(k,m))!=sost.end()){
            bool g=true;
            for(int i=0;i<n;++i)
                if(!a[i]){
                    g=false;
                    break;
                }
            cout<<(g?"YES":"NO");
            break;
        }
        //cout<<k<<' '<<m<<endl;
        sost.insert(pi(k,m));
        a[m]=true;
        m+=k;
        ++k;
        m%=n;
        k%=n;
    }
}