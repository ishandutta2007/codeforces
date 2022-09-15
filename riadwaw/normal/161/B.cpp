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


struct tov{
    int id;
    int type;
    int c;
    
    bool operator < (const tov& b) const{
        return type<b.type || (type==b.type && c>b.c);
    }
};

tov t[10000];


vector<tov> kor[100000];
bool have[10000];
void solve() {
    int n,k;
    cin>>n>>k;
    li sum = 0;
    for(int i=0;i<n;++i){
        cin>>t[i].c>>t[i].type;
        t[i].id = i+1;
        sum+=t[i].c;
    }
    sort(t, t+n);
    for(int i=0;i<k;++i){
        if(t[i].type==1)
            have[i] = true;
        kor[i].pb(t[i]);
    }
    
    for(int i=k;i<n;++i){
        if(t[k-1].type==1)
            have[k-1] = true;
        kor[k-1].pb(t[i]);
    }
    li s = 0;
    for(int i=0;i<k;++i){
        if(!have[i])
            continue;
        li ss=kor[i][0].c;
        for(int j=0;j<(int)kor[i].size();++j){
            ss=min(ss,(li)kor[i][j].c);
        }
        s+=ss;
    }
    li db = 2*sum - s;
    cout<<db/2<<'.'<<((db%2)*5)<<endl;
    for(int i=0;i<k;++i){
        cout<<kor[i].size()<<' ';
        for(int j=0;j<(int)kor[i].size();++j){
            cout<<kor[i][j].id<<' ';
        }
        cout<<'\n';
    }
}