#include <iostream>
#include <cstdio>
#include <set>
#include <list>
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
    //ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

void solve(){
    
    int x;
    cin>>x;
    if(x == 3){
        cout<<5;
        return;
    }
    for(int n = 1;;n+=2){
        int mx = n*n/2 + 1;
        if(mx>=x){
            cout<<n<<endl;
            return;
        }
    }

    
}