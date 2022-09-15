#pragma comment(linker,"/STACK:64000000")
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <complex>
#include <memory.h>
#include <bitset>
#include <math.h>
#define PI      3.14159265358979323846
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<li, li> pli;
typedef long double ld;
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
#endif
    solve();
    return 0;
}
void solve(){
    set<int> m[26];
    int n,k;
    cin>>n>>k;
    char s[200002];
    scanf("%s",s);
    for(int i=0;i<k;++i){
        m[s[i]-'a'].insert(i);
    }
    for(int i=0;i<n;++i){
        li ans=0;
        scanf("%s",s);
        for(int j=0,l=strlen(s);j<l;++j)
            if(m[s[j]-'a'].empty())
                ans+=l;
            else{
                set<int>::iterator it=m[s[j]-'a'].lower_bound(j);
                int best=10000000;
                if(it!=m[s[j]-'a'].end())
                    best=(*it-j);
                if(it!=m[s[j]-'a'].begin()){
                    --it;
                    best=min(best,j-*it);
                }
                ans+=best;
            }
        cout<<ans<<endl;
    }
}