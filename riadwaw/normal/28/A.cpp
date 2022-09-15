#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <math.h>
#include <sstream>
#include <complex>
#include <string.h>
#include <algorithm>
using namespace std;

void solve();
#define mp make_pair
#define pb push_back
typedef int fknmain;
typedef long long int li;
//#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;

fknmain main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
    #define INT "%lld"
#else
    #define INT "%I64d"
#endif
#ifndef int
    #undef INT
    #define INT "%d"
#endif
    solve();
    return 0;
}
void solve(){
    int n,m;
    cin>>n>>m;
    pi a[555];
    int g[555];
    if(n&1){
        cout<<"NO";
        return;
    }
    for(int i=0;i<n;++i){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=0;i<n;++i){
        g[i]=abs(a[i].first-a[(i+1)%n].first)+abs(a[i].second-a[(i+1)%n].second);
    }
    map<int,int> m1,m2;
    map<int,set<int> > s;
    for(int i=0;i<m;++i){
        int x;
        cin>>x;
        ++m1[x],++m2[x];
        s[x].insert(i+1);
    }
    int f=true;
    for(int i=0;i<n;i+=2){
        if(!m1[g[i]+g[i+1]]){
            f=false;
            break;
        }
        --m1[g[i]+g[i+1]];
    }
    if(f){
        cout<<"YES\n";
        for(int i=0;i<n;i+=2){
            cout<<"-1 "<<*s[g[i]+g[i+1]].begin()<<' ';
            s[g[i]+g[i+1]].erase(s[g[i]+g[i+1]].begin());
        }
        return;
    }
    
    f=true;
    for(int i=1;i<n;i+=2){
        if(!m2[g[i]+g[(i+1)%n]]){
            f=false;
            break;
        }
        --m2[g[i]+g[(i+1)%n]];
    }
    
    if(f){
        cout<<"YES\n";
        cout<<*s[g[0]+g[n-1]].begin();
        s[g[0]+g[n-1]].erase(s[g[0]+g[n-1]].begin());
        cout<<' ';
        for(int i=1;i<n-2;i+=2){
            cout<<"-1 "<<*s[g[i]+g[i+1]].begin()<<' ';
            s[g[i]+g[i+1]].erase(s[g[i]+g[i+1]].begin());
        }
        cout<<"-1";
        return;
    }
    
    cout<<"NO";
}