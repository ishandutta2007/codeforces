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
const int mod = 1000000007;
int dsu[2222];
int get(int a){
    if(dsu[a]==a)
        return a;
    else
        return dsu[a]=get(dsu[a]);
}

void ob(int a,int b){
    dsu[get(a)]=get(b);
}

li binpow(li a,li b){
    if(!b)
        return 1;
    if(b&1)
        return (a*binpow(a,b-1))%mod;
    return binpow((a*a)%mod,b>>1);
}
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        dsu[i] = i;
    }
    for(int i=0;i+k<=n;++i){
        for(int j=0;j<k;++j){
            ob(i+j,i+k-1-j);
        }
    }

    set<int> s;
    for(int i=0;i<n;++i){
        s.insert(get(i));
    }

    cout<<binpow(m,s.size());

}