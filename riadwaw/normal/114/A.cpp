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

using namespace std;
void solve();

#define mp make_pair
#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}

void solve(){
    li k,l;
    cin>>k>>l;
    int n=0;
    li r=k;
    while(r<l){
        ++n;
        r*=k;
    }
    if(r==l)
        cout<<"YES "<<n;
    else
        cout<<"NO";
}