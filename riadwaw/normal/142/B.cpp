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
    int n,m;
    cin>>n>>m;
    if(n>m){
        swap(n,m);
    }

    if(n==1){
        cout<<m;
        return;
    }
    if(n==2){
        cout<<2*(m/4*2+min(2,m%4));
        return;
    }
    cout<<((n*m+1)/2);

}