#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;

const int maxn  =   105;

VI row[maxn];
int n,m,p[maxn];

inline int dist(int x)
{
    int res=min(abs(x),abs(x-m));
    res=min(res,abs(x+m));
    return res;
}

inline int getDist(VI &a,int x,int &j)
{
    while (j+1<a.size() && a[j+1]<=x) ++j;
    
    int i=j;
    int res=-1;
    if (a.size()){
        res=min(dist(a[0]-x),dist(a.back()-x));
    }
    if (i>=0 && i<a.size()){
        if (res==-1 || dist(a[i]-x)<res){
            res=dist(a[i]-x);
        }
    }
    ++i;
    if (i>=0 && i<a.size()){
        if (res==-1 || dist(a[i]-x)<res){
            res=dist(a[i]-x);
        }
    }
    return res;
}
char s[10005];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i){
        scanf("%s",s);
        row[i].clear();
        for (int j=0;j<m;++j){
            if (s[j]=='1'){
                row[i].PB(j);
            }
        }
    }
    
    int ans=-1;
    for (int i=0;i<n;++i){
        p[i]=0;
    }
    for (int col=0;col<m;col++){
        int t=0;
        for (int i=0;i<n;++i){
            int d=getDist(row[i],col,p[i]);
            if (d!=-1) t+=d;
            else{
                t=-1;
                break;
            }
        }
        if (t!=-1){
            if (ans==-1 || ans>t){
                ans=t;
            }
        }
    }
    
    printf("%d\n",ans);
    return 0;
}