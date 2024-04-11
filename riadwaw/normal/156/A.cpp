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
void prec();

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
    while(t--)
        solve();
    return 0;
}

li dsu[101010];
int get(int a){
    if(a==dsu[a])
        return a;
    return dsu[a]=get(dsu[a]);
}
int cnt[101010];
void unite(int a,int b){
    dsu[get(a)]=get(b);
}
vector<int> v;
void solve(){
    string s,t;
    cin>>s>>t;
    //if(s.size()>t.size())
    //  s.swap(t);
    int mx=0;
    for(int d = -2000;d<=2000;++d){
        int cur = 0;
        for(int i=0;i<t.size();++i){
            if((i+d>=0) &&( i+d< s.size())&& t[i]==s[i+d])
                ++cur;
        }
        mx = max(mx,cur);
    }
    cout<<t.size()-mx;
}