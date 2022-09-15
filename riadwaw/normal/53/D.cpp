#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<li,li> pli;
void solve();
int main(){
#ifdef DEBUG
    freopen("input","r",stdin);
#endif
    solve();
    return 0;
}
int need[333];
int have[333];
vector<pi> d;
void proc(int c){
    if(c==1)
        return;
    int i=c-1;
    while(have[i]!=need[c-1])
        i--;
    for(;i<c-1;++i){
        swap(have[i],have[i+1]);
        d.push_back(pi(i+1,i+2));
    }
    proc(c-1);
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>need[i];
    for(int i=0;i<n;++i)
        cin>>have[i];
    proc(n);
    cout<<d.size()<<'\n';
    for(int i=0,s=d.size();i<s;++i)
        cout<<d[i].first<<' '<<d[i].second<<'\n';
}