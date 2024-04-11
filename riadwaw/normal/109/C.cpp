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
/**
 CAUTION Is int really int?
 * 
 Real solution after main function
 */
//#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;

fknmain main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    freopen("output","w",stdout);
#define LL "%lld"
#else
#define LL "%I64d"
#endif
#ifndef int
#define INT "%d"
#else
#define INT LL
#endif
    solve();
    return 0;
}

int dsu[101010];
int cntdsu[101010];

int find(int v){
    if(dsu[v]==v)
        return v;
    return dsu[v]=find(dsu[v]);
}

void un(int a,int b){
    dsu[find(a)]=find(b);
}



bool is_good(int n){
    while(n){
        int o=n%10;
        if(o!=7 && o!=4)
            return false;
        n/=10;
    }
    return true;
}

vi g[101010];
li sqr(int a){
    return (li)a*(a-1);
}
void solve(){
    int n;
    cin>>n;
    
    for(int i=1;i<=n;++i)
        dsu[i]=i;
    
    for(int i=1;i<n;++i){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(!is_good(c)){
            un(a,b);
        }
    }
    
    for(int i=1;i<=n;++i){
        cntdsu[find(i)]++;
    }
    
    li ans=0;
    for(int i=1;i<=n;++i){
        ans+=sqr(n-cntdsu[find(i)]);
    }
    
    cout<<ans;
    
    
}