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

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
void solve(){
    li a[3],k;
    cin>>a[0]>>a[1]>>a[2]>>k;
    sort(a,a+3);
    li x1=min(a[0]-1,k/3);
    k-=x1;
    li x2=min(a[1]-1,k/2);
    k-=x2;
    li x3=min(a[2]-1,k);
    cout<<(x1+1)*(x2+1)*(x3+1);

}