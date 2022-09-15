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

void solve();
#define mp make_pair
#define pb push_back
int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
    #define INT "%lld"
#else
    #define INT "%I64d"
#endif
    solve();
    return 0;
}
typedef long long int li;
#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;


void solve(){
    int n;
    scanf(INT,&n);
    vi v;
    for(int i=0;i<n;++i){
        char c,d;
        scanf("\n%c%c%c",&d,&c,&c);
        int x;
        switch(d){
            case 'a':               
                scanf(INT,&x);
                v.insert(lower_bound(v.begin(),v.end(),x),x);
                break;
            case 'd':
                scanf(INT,&x);
                v.erase(lower_bound(v.begin(),v.end(),x));
                break;
            case 's':
                int s=0;
                for(int i=2;i<v.size();i+=5){
                    s+=v[i];
                }
                printf(INT"\n",s);
        }
    }
}