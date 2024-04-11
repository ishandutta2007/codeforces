#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
const int maxn=1e5+10;
vector<int> c[maxn],r[maxn];
int n,m,k,x[maxn],y[maxn];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=k; i++){
        scanf("%d%d",&x[i],&y[i]);
        r[x[i]].push_back(y[i]);
        c[y[i]].push_back(x[i]);
    }
    for (int i=1; i<=n; i++) r[i].push_back(0),r[i].push_back(m+1);
    for (int i=1; i<=m; i++) c[i].push_back(0),c[i].push_back(n+1);
    for (int i=1; i<=n; i++) sort(r[i].begin(),r[i].end());
    for (int i=1; i<=m; i++) sort(c[i].begin(),c[i].end());
    int x=1,y=1,d=0,l=0,rr=m+1,u=1,b=n+1;
    int _y=*upper_bound(r[1].begin(),r[1].end(),1)-1;
    if (_y<=y) d=1,rr=y; 
    long long cnt=1;
    while (1){
 
        if (d==0){
            int _y=*upper_bound(r[x].begin(),r[x].end(),y)-1;
            if (_y>=rr) _y=rr-1;
            if (_y<=y) break;
            cnt+=_y-y;
            y=_y; d=(d+1)%4; rr=y;
        }else if (d==1){
            int _x=*upper_bound(c[y].begin(),c[y].end(),x)-1;
            if (_x>=b) _x=b-1;
            if (_x<=x) break;
            cnt+=_x-x;
            x=_x; d=(d+1)%4; b=x;
        }else if (d==2){
             int _y=*(lower_bound(r[x].begin(),r[x].end(),y)-1)+1;
            if (_y<=l) _y=l+1;
            if (_y>=y) break;
            cnt+=y-_y;
            y=_y; d=(d+1)%4; l=y;
        }else if (d==3){
            int _x=*(lower_bound(c[y].begin(),c[y].end(),x)-1)+1;
            if (_x<=u) _x=u+1;
            if (_x>=x) break;
            cnt+=x-_x;
            x=_x; d=(d+1)%4; u=x;
        }
       // printf("%d %d\n",x,y);
    }
    if (cnt+k!=1ll*n*m) puts("No"); else puts("Yes");
    return 0;
}