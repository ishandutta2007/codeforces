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
#include <unordered_map>
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
    int a,b,c,s;
    cin>>s>>a>>b>>c;
    if(a==0 && b==0 && c==0)
        a++,b++,c++;
    printf("%.20lf %.20lf %.20lf ",
            a*s/(a+b+c+ 0.0),
            b*s/(a+b+c + 0.0),
            c*s/(a+b+c + 0.0)
            );
}