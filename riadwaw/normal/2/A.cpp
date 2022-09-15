#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<li, li> pli;
typedef double ld;
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
    int n;
    cin>>n;
    vector<pair<string,int> > v;
    map<string,int> m;
    for(int i=0;i<n;++i){
        string a;
        int b;
        cin>>a>>b;
        v.pb(mp(a,b));
        m[a]+=b;
    }
    set<string> best;
    int res=-1<<30;
    for(map<string,int>::iterator it=m.begin();it!=m.end();++it){
        if(it->second>res){
            best.clear();
            best.insert(it->first);
            res=it->second;
        }
        else if(it->second==res){
            best.insert(it->first);
        }
    }
    m.clear();
    for(int i=0;i<n;++i){
        if((m[v[i].first]+=v[i].second)>=res && best.find(v[i].first)!=best.end()){
            cout<<v[i].first;
            return;
        }
    }
}