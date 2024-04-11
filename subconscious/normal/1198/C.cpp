#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define res(i,n) for(int i=0;i<n;++i)
#define eb emplace_back
#define mp make_pair
#define x0 fuckcjb
#define y0 fuckcxb
#define x1 fuckxjb
#define y1 fuckcjx
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=3e6+5,mod=1e9+7;
const ld eps=1e-9,inf=1e50;
int n,m,T;
bool tch[N];
vector<int>v;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);n*=3;
        rep(i,n)tch[i]=0;
        v.clear();
        rep(i,m){
            int x,y;scanf("%d%d",&x,&y);
            if(tch[x]==0&&tch[y]==0)
                tch[x]=1,tch[y]=1,v.eb(i);
        }
        if((int)v.size()>=n/3){
            puts("Matching");
            res(i,n/3)printf("%d%c",v[i]," \n"[i==n/3-1]);
        }else{
            puts("IndSet");
            int cnt=0;
            rep(i,n){
                if(tch[i]==0)printf("%d%c",i," \n"[(++cnt)==n/3]);
                if(cnt==n/3)break;
            }
        }
    }
    return 0;
}