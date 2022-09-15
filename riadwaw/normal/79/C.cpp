#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
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
bool eq(char *s,string& a){
    for(int i=0;i<a.size();++i){
        if(s[i]!=a[i])
            return false;
    }
    return true;
}
void solve(){
    pi bestans(0,0);
    int n;
    char s[101010];
    string b[12];
    scanf("%s%d",s,&n);
    int len=strlen(s);
    for(int i=0;i<n;++i){
        cin>>b[i];
    }
    for(int l=0,r=0;r<len;++r){
        for(int i=0;i<n;++i){
            if(r-b[i].length()+1>=l){
                if(eq(s+r-b[i].length()+1,b[i])){
                    l=r-b[i].length()+2;
                }
            }           
        }
        if(r-l+1>bestans.first){
            bestans=pi(r-l+1,l);
        }
    }
    cout<<bestans.first<<' '<<bestans.second;
}