//#define int li
//
//  NO int32 overflow!!!!!
// this line uncommented after main
//
//
//
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

using namespace std;
void solve();

#define mp make_pair
#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}

#define int li
int gcd(int a,int b){
    if(!b)
        return a;
    return gcd(b,a%b);
}
void solve(){
    li t1,t2,x1,x2,t0;
    cin>>t1>>t2>>x1>>x2>>t0;

        if(t1==t2)
            cout<<x1<<' '<<x2;
        else if(t0==t1)
        cout<<x1<<' '<<0;
    else if(t0==t2)
        cout<<0<<' '<<x2;
    else{
        int d1=t0-t1;
        int d2=t2-t0;
        int g=gcd(d1,d2);
        d1/=g;
        d2/=g;
        int k=min(x2/d1,x1/d2);
        if(k==0){
            int ans=0;
            int ans2=x2;
            for(int i=1;i<=x1;++i){
                int y2=(i*d1+d2-1)/(d2);
                if(y2>x2)
                    continue;
                if(ans==-1 || y2*ans<=ans2*i){
                    ans=i;
                    ans2=y2;
                }
            }
                cout<<ans<<' '<<ans2;
            return;
        }

        cout<<d2*k<<' '<<d1*k;
    }
}