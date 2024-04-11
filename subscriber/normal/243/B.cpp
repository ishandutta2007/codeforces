#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int x,y,n,m,t,h,yy[444444],pp[444444],xx[444444],kk,f[444444],ff[444444],s[444444];
vector<int>at,ah;

int main(){
//  freopen("1.in","r",stdin);  
//  freopen("1.out","w",stdout);    
    cin >> n >> m >> h >> t;
    for (int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        x--;
        y--;
        yy[++kk]=y;
        pp[kk]=xx[x];
        xx[x]=kk;
        yy[++kk]=x;
        pp[kk]=xx[y];
        xx[y]=kk;
        s[x]++;
        s[y]++;
    }
    for (int i=0;i<n;i++)for (int w=xx[i];w;w=pp[w]){
        x=i;
        y=yy[w];
        if (s[x]-1<h||s[y]-1<t)continue;
        at.clear();
        ah.clear();
        for (int q=xx[x];q;q=pp[q])if (yy[q]!=y)f[yy[q]]=1;
        for (int q=xx[y];q;q=pp[q])if (yy[q]!=x)ff[yy[q]]=1;
        for (int q=xx[x];q;q=pp[q])if (yy[q]!=y&&!ff[yy[q]]&&ah.size()<h)ah.pb(yy[q]);
        for (int q=xx[y];q;q=pp[q])if (yy[q]!=x&&!f[yy[q]]&&at.size()<t)at.pb(yy[q]);
        for (int q=xx[x];q;q=pp[q])if (f[yy[q]]&&ff[yy[q]]){
            if (ah.size()<h)ah.pb(yy[q]);else
            if (at.size()<t)at.pb(yy[q]);
        }
        if (ah.size()==h&&at.size()==t){
            puts("YES");
            cout << x+1 << " " << y+1 << endl;
            for (int i=0;i<h-1;i++)cout << ah[i]+1 << " ";
            CC(ah[h-1]+1);
            for (int i=0;i<t-1;i++)cout << at[i]+1 << " ";
            CC(at[t-1]+1);
            return 0;
        }
        for (int q=xx[x];q;q=pp[q])if (yy[q]!=y)f[yy[q]]=0;
        for (int q=xx[y];q;q=pp[q])if (yy[q]!=x)ff[yy[q]]=0;

    }
    CC("NO");
    return 0;
}