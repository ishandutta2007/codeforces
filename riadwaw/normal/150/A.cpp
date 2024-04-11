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
//typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
void solve() {
    li n;
    cin>>n;
    vector<li> d;
    for(li i=2;i*i<=n;++i){
        if(n%i)
            continue;
        d.push_back(i);
        if(i*i!=n){
            d.push_back(n/i);
        }
    }
    sort(d.begin(),d.end());
    if(d.size()==0)
        cout<<1<<endl<<0<<endl;
    else if(d.size()==1){
        cout<<2<<endl;
    }
    else if(d[0]*d[0]==d[1])
        cout<<1<<endl<<d[1];
    else if(d[0]*d[1]==n)
        cout<<2;
    else
        cout<<1<<endl<<(d[0]*d[1]);

}