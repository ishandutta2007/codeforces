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
#define pb push_back
int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
void solve(){
    int a[4];
    for(int i=0;i<4;++i)
        cin>>a[i];
    bool seg=0;
    sort(a,a+4);
    do{
        if(a[0]<a[1]+a[2] && a[1]<a[0]+a[2] && a[2]<a[0]+a[1]){
            cout<<"TRIANGLE";
            return;
        }
        else if(a[0]==a[1]+a[2])
            seg=1;
    }
    while(next_permutation(a,a+4));
    cout<<(seg?"SEGMENT":"IMPOSSIBLE");
}