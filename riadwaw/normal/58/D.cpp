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
char d;
void solve(){
    set<string> r[11];
    string s[11111];    
    int n;
    cin>>n;
    li sum=0;
    for(int i=0;i<n;++i){
        cin>>s[i];
        r[s[i].size()].insert(s[i]);
        sum+=s[i].size();
    }
    sum=(2*sum)/n+1;
    cin>>d;
    set<string> st;
    for(int i=0;i<n;++i){
        st.insert(s[i]+d);
    }
    while(!st.empty()){
        string first=*st.begin();
        st.erase(first);
        r[first.size()-1].erase(first.substr(0,first.size()-1));
        cout<<first<<*(r[sum-first.size()].begin())<<'\n';
        st.erase(*(r[sum-first.size()].begin())+d);     
        r[sum-first.size()].erase(r[sum-first.size()].begin());
        
    }
}