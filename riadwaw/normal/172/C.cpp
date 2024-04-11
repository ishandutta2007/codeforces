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
    freopen("output","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
struct man{
    int id;
    li x;
    bool operator <(const man& b) const{
        return x<b.x || (x==b.x && id<b.id);
    }
};
man chel[101010];
li ans[101010];
void solve(){
    li n,m;
    cin>>n>>m;
    li lastt = 0;
    for(int z=0, cnt= (m+n-1)/m;z<cnt;++z){
        if((z+1)*m>n)
            m = n%m;
        for(int j=0;j<m;++j){
            li t;
            chel[j].id = j;
            cin>>t>>chel[j].x;
            lastt=max(lastt,t);
        }
        sort(chel, chel + m);
        li add = 0;
        int curind = 0;
        int k=0;
        while(true){
            if(curind >=m)
                break;
            if(k<m && chel[curind].x == chel[k].x)
                ++k;
            else{
                for(int i=curind;i<k;++i){
                    ans[chel[i].id] = add + lastt + chel[i].x;
                    
                }
                add += 1 + (k - curind)/2;
                curind = k;
            }
        }
        lastt += add + chel[m-1].x * 2;
        
        for(int i=0;i<m;++i){
            cout<<ans[i]<<' ';
        }
    }
}