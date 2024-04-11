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
typedef vector<li> vi;
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

map<int,int> mapa;
void solve(){
    int a,b,m,r;
    cin>>a>>b>>m>>r;
    for(int i=1;true;++i, r=(a*r+b)%m){
        //cout<<r<<endl;
        if(mapa.find(r)==mapa.end())
            mapa[r] = i;
        else{
            cout<<i-mapa[r];
            return;
        }
    }
}