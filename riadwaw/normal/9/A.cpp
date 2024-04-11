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
    int a,b;
    cin>>a>>b;
    int c=7-max(a,b);
    cout<<(c==6?"1/1":c==5?"5/6":c==4?"2/3":c==3?"1/2":c==2?"1/3":"1/6");
}