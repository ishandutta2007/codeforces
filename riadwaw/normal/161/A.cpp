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
typedef vector<int> vi;
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
pi sman[101010];
pi sbr[101010];
vector<pi> v;
void solve() {
    pi * man =sman;
    pi * br = sbr; 
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    for(int i=0;i<n;++i){
        man[i].second=i+1;
        cin>>man[i].first;
    }
    for(int i=0;i<m;++i){
        br[i].second=i+1;
        cin>>br[i].first;
    }
    //sort(man,man + n);
    //sort(br,br + m);
    
    pi* eman = man + n;
    pi* ebr = br + m;
    while(eman!=man && ebr!=br){
        if(br->first < man->first - x){
            ++br;
        }
        else if(br->first > man->first + y){
            ++man;
        }
        else{
            v.pb(mp(man->second,br->second));
            ++man;
            ++br;
        }
    }
    
    cout<<v.size()<<endl;
    for(int i=0;i<int(v.size());++i){
        cout<<v[i].first<<' '<<v[i].second<<endl;
    }
    
    
}