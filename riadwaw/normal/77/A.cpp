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
    solve();
    return 0;
}
#define int li

string m[]={string("Anka"),string("Chapay"),string("Cleo"),string("Troll"),string("Dracul"),string("Snowy"),string("Hexadecimal")};
int find(string c){
    int i=0;
    while(m[i]!=c)
        ++i;
    return i;
}

bool l[8][8];
pli res(1<<30,0);
int exp[5];
int now[10];
void check(){
    int f[3]={0,0,0};
    for(int i=0;i<7;++i)
        ++f[now[i]];
    for(int i=0;i<3;++i)
        if(!f[i])
            return;
    int a[5];
    for(int i=0;i<3;++i){
        a[i]=exp[i]/f[i];
    }
    pli r(max(max(a[0],a[1]),a[2])-min(min(a[0],a[1]),a[2]),0);
    for(int i=0;i<7;++i)
        for(int j=0;j<7;++j)
            if(now[i]==now[j] && l[i][j])
                r.second++;
    if(r.first<res.first || r.first==res.first && r.second>res.second)
        res=r;

}
void d(int k){
    if(k==7){
        check();
        return;
    }
    for(int i=0;i<3;++i){
        now[k]=i;
        d(k+1);
    }
}
void solve(){
    int n;
    cin>>n;
    string a,b,g;
    
    // Anka,  Chapay,  Cleo,  Troll,  Dracul,  Snowy   - Hexadecimal
    
    for(int i=0;i<n;++i){
        cin>>a>>g>>b;
        l[find(a)][find(b)]=true;
    }
    for(int i=0;i<3;++i)
        cin>>exp[i];
    d(0);
    cout<<res.first<<' '<<res.second;
}