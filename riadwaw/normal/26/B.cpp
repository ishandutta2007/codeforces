#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <complex>
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
typedef double ld;
void solve();

#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    solve();
    return 0;
}
#define int li
void solve(){
    int s=0,l=0;
    char c;
    while(cin>>c){
        if(c=='(')
            ++s,++l;
        else if(c==')'){
            if(s)
                --s,++l;
        }
        else
            break;
    }
    cout<<l-s;
}