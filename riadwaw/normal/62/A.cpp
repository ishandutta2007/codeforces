#pragma comment(linker,"/STACK:64000000")
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <complex>
#include <memory.h>
#include <bitset>
#include <math.h>
#define PI      3.14159265358979323846
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<li, li> pli;
typedef long double ld;
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
#endif
    solve();
    return 0;
}
#define N 1000002
bitset<N> a,b,c;

int f(int a,int b){
    if(b<a-1)
        return false;
    if(a*2<b-2)
        return false;
    return true;
}
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(f(a,d) || f(b,c))
        cout<<"YES";
    else
        cout<<"NO";
}