#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <sstream>
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
    //freopen("output","w", stdout);
#endif
    //ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
int c[1111][1111];
void solve(){
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>c[i][j];
        }
    }
    
    li ans = 0;
    li x, y;
    {
        int sum[1111];
        for(int j=0;j<m;++j){
            sum[j] = 0;
            for(int i=0;i<n;++i){
                sum[j] += c[i][j];
            }
        }
        
        li curans = 1LL<<61;
        int bestbef = -1;
        for(int bef = 0;bef<=m;++bef){
            
            li cur = 0;
            for(int i=0;i<m;++i){
                li rast = (bef <= i) ? (4 * (i - bef) + 2) : (4*(bef-i) - 2) ;
                //cerr<<bef<<' '<<i<<' '<<rast<<' '<<endl;
                rast *= rast;
                cur+= sum[i] * rast;
            }
            //cerr<<endl;
            
            if(cur < curans){
                bestbef = bef;
                curans = cur;
            }
        }
        
        ans+=curans;
        x=bestbef;
    }
    {
        int sum[1111];
        for(int i=0;i<n;++i){
            sum[i] = 0;
            for(int j=0;j<m;++j){
                sum[i] += c[i][j];
            }
        }
        
        li curans = 1LL<<61;
        int bestbef = -1;
        for(int bef = 0;bef<=n;++bef){
            
            li cur = 0;
            for(int i=0;i<n;++i){
                li rast = (bef <= i) ? (4 * (i - bef) + 2) : (4*(bef-i) - 2) ;
                rast *= rast;
                cur+= sum[i] * rast;
            }
            
            
            
            if(cur < curans ){
                bestbef = bef;
                curans = cur;
            }
            
            //cerr<<bef<<' '<<cur<<' '<<curans<<' '<<bestbef<<endl;
        }
        //cout<<curans<<endl;
        ans+=curans;
        y=bestbef;
    }
    cout<<ans<<endl<<y<<' '<<x;
}