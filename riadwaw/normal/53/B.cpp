#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<li,li> pli;
void solve();
int main(){
#ifdef DEBUG
    freopen("input","r",stdin);
#endif
    solve();
    return 0;
}
void solve(){
    int w,h;
    cin>>w>>h;
    pli mn;
    for(li i=1;i<=w;i=i<<1){
        li ww=i;
        li hh=min(h,(int)(i*1.25));
        if(hh<0.8*i)
            break;
        if(ww*hh>mn.first*mn.second || (ww*hh==mn.first*mn.second && ww>mn.first)){
            mn=pli(ww,hh);
        }
    }
    for(li i=1;i<=h;i=i<<1){
        li hh=i;
        li ww=min(w,(int)(i*1.25));
        if(ww<0.8*i)
            break;
        if(ww*hh>mn.first*mn.second ||( ww*hh==mn.first*mn.second && ww>mn.first)){
            mn=pli(ww,hh);
        }
    }
    cout<<mn.first<<' '<<mn.second;
}