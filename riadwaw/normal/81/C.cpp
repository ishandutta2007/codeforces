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
    //freopen("output","w",stdout);
#endif
    solve();
    return 0;
}

void solve(){
    
    int n,a,b;
    cin>>n>>a>>b;
    pi x[101010];
    for(int i=0;i<n;++i){
        scanf("%d",&x[i].first);
    }
    if(a==b){
        for(int i=0;i<a;++i){
            printf("1 ");
        }
        for(int i=0;i<a;++i){
            printf("2 ");
        }
        return;
    }
    int ans[101010];
    if(a>b){
        for(int i=0;i<n;++i){
            x[i].second=i;
        }
        sort(x,x+n);
        for(int i=0;i<a;++i){
            ans[x[i].second]=1;
        }
        for(int i=a;i<n;++i){
            ans[x[i].second]=2;
        }
        for(int i=0;i<n;++i)
            printf("%d ",ans[i]);
    }
    if(a<b){
        for(int i=0;i<n;++i){
            x[i].second=-i;
        }
        sort(x,x+n);
        for(int i=0;i<b;++i){
            ans[-x[i].second]=2;
        }
        for(int i=b;i<n;++i){
            ans[-x[i].second]=1;
        }
        for(int i=0;i<n;++i)
            printf("%d ",ans[i]);
    }
}