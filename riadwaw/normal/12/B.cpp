#include <set>
#include <map>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
typedef pair<int,int> pi;
typedef long long int li;
typedef vector<int> vi;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input","r",stdin);
#endif
    solve();
    return 0;
}
void solve(){
    string a,b;
    cin>>a>>b;
    sort(a.begin(),a.end());
    int i=0;
    while(a[i]=='0')
        ++i;
    if(i<a.length())
        swap(a[i],a[0]);
    cout<<(a==b?"OK":"WRONG_ANSWER");
}