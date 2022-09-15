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
    //freopen("output","w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
void solve(){
    int n;
    cin>>n;
    map<string, int> m;
    for(int i=0;i<n;++i){
        string s;
        int pts;
        cin>>s>>pts;
        m[s]=max(m[s], pts);
    }
    cout<<m.size()<<endl;
    for(auto me: m){
        int cnt = 0;
        for(auto other: m){
            
            if(me.second>=other.second){
                ++cnt;
            }
        }
        cout<<me.first<<' ';
        if(100 * cnt >= 99 * m.size())
            cout<<"pro";
        else if(100 * cnt >= 90 * m.size())
            cout<<"hardcore";
        else if(100 * cnt >= 80 * m.size())
            cout<<"average";
        else if(100 * cnt >= 50 * m.size())
            cout<<"random";
        else
            cout<<"noob";
            cout<<endl;
    }
}