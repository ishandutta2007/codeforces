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
    vi p;
    p.pb(2);
    int n;
    cin>>n;
    for(int i=3;i<=n;++i){
        bool f=true;
        for(int j=0;j<p.size();++j){
            if(i%p[j]==0){
                f=false;
                break;
            }
        }
        if(f)
            p.pb(i);
    }
    int res=0;
    for(int i=1;i<=n;++i){
        int ans=0;
        for(int j=0;j<p.size();++j){
            if(i%p[j]==0)
                ++ans;
        }
        if(ans==2)
            res++;
    }
    
    cout<<res;

}