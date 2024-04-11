#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <complex>
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
typedef double ld;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    solve();
    return 0;
}
void solve(){
    map<string,int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        ++m[s];
    }
    string ans=m.begin()->first;
    auto it=++m.begin();
    if(it!=m.end() && it->second>m[ans])
        ans=it->first;
    cout<<ans;
}