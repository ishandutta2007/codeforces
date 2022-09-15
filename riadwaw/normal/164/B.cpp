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
    //freopen("output","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

int a[1010101];
int b[1010101];
int where[1010101];
void solve(){
    int n,m;
    cin>>n>>m;
    memset(where, -1, sizeof(where));
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<m;++i){
        cin>>b[i];
        where[b[i]] = i;
    }
    int ans = 0;
    int r = 0;
    bool per = false;
    for(int l=0;l<n;++l){
        if(r<l)
            r=l;
        int start = where[a[l]];
        //cout<<' '<<l<<' '<<r<<' '<<start<<endl;
        if(start==-1){
            continue;
        }
        per = where[a[r%n]] < start;
        while(true){
            if(r == l + n){
                ans = n;
                break;
            }
            //cout<<l<<' '<<r<<' '<<start<<' '<<per<<endl;
            if(where[a[(r+1)%n]] == -1){
                ans = max(ans,r-l+1);
                break;
            }
            if(where[a[(r+1)%n]] < where[a[r%n]]){
                if(per){
                    ans = max(ans,r-l+1);
                    break;
                }
                else if(where[a[(r+1)%n]] > start){
                    ans = max(ans,r-l+1);
                    break;
                }
                else
                    per = true;
            }
            else{
                if(per){
                    if(where[a[(r+1)%n]] > start){
                        ans = max(ans, r-l +1);
                        break;
                    }
                }
            }
            ++r;
        }
        //cout<<ans<<endl;
    }
    cout<<ans;
}