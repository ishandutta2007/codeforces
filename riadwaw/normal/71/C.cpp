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
typedef long long int li;
#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;




void solve(){
    vi p;
    int n,a[111110];
    cin>>n;
    int m=n;
    for(int i=0;i<n;++i){
        scanf("%lld",a+i);
    }
    for(int i=2;i*i<=n;++i){
        while(n%i==0)
            p.pb(i),n/=i;
    }
    if(n>1)
        p.pb(n);
    n=m;
    for(int i=0;i<p.size();++i){
        if(p[i]==2){
            if(i+1<p.size() && p[i+1]==2){
                p[i]=4;
            }
            else continue;
        }
        for(int j=0;j<(n/p[i]);++j){
            bool g=true;
            for(int k=j;k<n;k+=(n/p[i])){
                if(!a[k]){
                    //cout<<p[i]<<' '<<j<<' '<<k<<' '<<endl;
                    g=false;
                    break;
                }
            }
            if(g){
                //cerr<<p[i]<<' '<<j;
                cout<<"YES";
                return;
            }
        }
    }
    cout<<"NO";
}