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
void solve(){
    int n;
    cin>>n;
    map<int,int> m;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        m[a-min(i,n-1-i)]++;
    }
    int mx=0;
    for(map<int,int>::iterator i=m.begin();i!=m.end();++i){
        if((i->first)>0 && (i->second)>mx)
            mx=i->second;
    }
    cout<<n-mx;
}