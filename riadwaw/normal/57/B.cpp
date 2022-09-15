#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long li;
typedef pair<li, li> pli;
typedef long double ld;
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
struct query{
    int l,r,x;
    query(){}
    void fill(){
        cin>>l>>r>>x;
    }
    li get(int a){
        if(a<l || a>r)
            return 0;
        return a-l+x;
    }
};
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    query q[111111];
    for(int i=0;i<m;++i){
        q[i].fill();
    }
    li res=0;
    for(int i=0;i<k;++i){
        int a;
        cin>>a;
        for(int j=0;j<m;++j){
            res+=q[j].get(a);
        }
    }
    cout<<res;
}