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
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vi p;
    for(int i=2;i<=n;++i){
        bool f=true;
        for(int j=2;j*j<=i;++j){
            if(i%j==0)
                f=false;
        }
        if(f)
            p.pb(i);
    }
    int c=0;
    for(int i=0;i<p.size();++i){
        for(int j=0;j<(int)p.size()-1;++j){
            if(p[j]+p[j+1]+1==p[i]){
                ++c;
                break;
            }
        }
    }
    cout<<(c>=k?"YES":"NO");
}