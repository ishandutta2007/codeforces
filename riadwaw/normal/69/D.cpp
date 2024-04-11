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
pi a[202];
bool res[402][402];
int d,n;
bool use[402][402];
int rec(int x,int y){
    if(x*x+y*y>d*d)
        return false;
    if(use[x+200][y+200])
        return res[x+200][y+200];
    use[x+200][y+200]=true;
    for(int i=0;i<n;++i)
        if(rec(x+a[i].first,y+a[i].second)){
            return false;
        }
    res[x+200][y+200]=true;
    return true;
}
void solve(){
    int x,y;
    cin>>x>>y>>n>>d;
    for(int i=0;i<n;++i){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    if(rec(x,y)){
        cout<<"Dasha";
    }
    else
        cout<<"Anton";
}