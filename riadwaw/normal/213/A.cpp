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
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
int pc[222];
vector<set<int> > depends, dependscopy;
set<int> emptydep, emptydepcopy;
bool deleted[222];
void solve(){
    int n;
    cin>>n;
    for(int i= 0; i< n;++i){
        cin>>pc[i];
        --pc[i];
    }
    depends.assign(n, set<int>());
    
    
    for(int i = 0; i< n;++i){
        int k;
        cin>>k;
        for(int j = 0; j<k;++j){
            int l;
            cin>>l;
            --l;
            depends[i].insert(l);
        }
        if(k==0){
            emptydep.insert(i);
        }
    }
    
    dependscopy = depends;
    emptydepcopy =emptydep;
    
    int ans = 1000000000;
    for(int start = 0 ; start<3;++start){
        memset(deleted, false , sizeof deleted);
        depends = dependscopy;
        emptydep = emptydepcopy;
        int cur = start;
        int res= 0;
        bool changed = false;
        while(!emptydep.empty()){
            //cout<<"start\n";
            changed = false;
            set<int> todel;
            for(set<int>::iterator it=emptydep.begin(); it!=emptydep.end();++it){
                if(pc[*it] == cur){
                    todel.insert(*it);
                    //cout<<"del"<<*it<<endl;
                }
            }
            for(set<int>::iterator it=todel.begin(); it!=todel.end();++it){
                emptydep.erase(*it);
                deleted[*it] = true;
                changed = true;
                for(int i = 0; i < n; ++i){
                    depends[i].erase(*it);
                    if(depends[i].empty() && !deleted[i])
                        emptydep.insert(i);
                }
            }
            if(!changed){
                cur++;
                cur%=3;
                ++res;
            }
        }
        ans = min(res, ans);
    }
    
    cout<<ans + n;
}