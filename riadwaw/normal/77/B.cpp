#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<li, li> pli;
typedef double ld;
void solve();

#define mp make_pair
int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
        solve();
    return 0;
}
li a,b;
void solve(){   
    scanf("%d %d",&a,&b);
    double res=0;
    if(!b)
        res=1;
    else if(!a){
        res=0.5;
    }
    else if(4*b>=a)
        res=(a*b+a*a*0.125)/(2*a*b);
    else
        res=1-b*2*b/(double)(2*a*b);
    printf("%.12lf\n",res);

}