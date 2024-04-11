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

int sign(int a){
    if(a==0)
        return 0;
    else return a/abs(a);
}
void solve() {
    int n;
    cin>>n;
    for(int i=0;i<2*n+1;++i){
        int max=min(i,2*n-i);
        for(int j=0;j<n-max;++j){
            cout<<"  ";
        }
        cout<<0;

        for(int i=1;i<=max;++i)
            cout<<' '<<i;

        for(int i=max-1;i>=0;--i)
            cout<<' '<<i;

        cout<<endl;
    }
}