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
    int x,y;
    cin>>x>>y;
    for(int i=0;;++i){
        if(x*x+y*y==i*i){
            cout<<"black";
            return;
        }
        if(x*x+y*y<i*i){
            cout<<(((i+(x*y<0))%2)?"black":"white");
            return;
        }
    }
}