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
    map<int,int> kol;
    set<int> po1;
    int n,k,a[111111];
    cin>>n>>k;
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
    }
    for(int i=0;i<n;++i){
        ++kol[a[i]];
        if(kol[a[i]]==1)
            po1.insert(a[i]);
        else
            po1.erase(a[i]);
        if(i>=k){
            --kol[a[i-k]];
            if(kol[a[i-k]]==1)
                po1.insert(a[i-k]);
            else
                po1.erase(a[i-k]);
        }
        if(i>=k-1){
            if(po1.empty())
                printf("Nothing\n");
            else
                printf("%d\n",*po1.rbegin());
        }
    }
}