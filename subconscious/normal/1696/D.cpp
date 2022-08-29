#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
const int N=3e5+5,mod=1e9+7;
int T,n,a[N],dis[N];
int sta[2][N],top[2];
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        top[0]=top[1]=0;
        rep(i,n){
            while(top[0]>0&&a[sta[0][top[0]]]<a[i])--top[0];
            sta[0][++top[0]]=i;
            while(top[1]>0&&a[sta[1][top[1]]]>a[i])--top[1];
            sta[1][++top[1]]=i;
            if(i==1){
                dis[i]=0;
            }else{
                int r=(a[i-1]<a[i]);
                dis[i]=dis[*upper_bound(sta[r]+1,sta[r]+top[r]+1,sta[r^1][top[r^1]-1])]+1;
            }
            // rep(i,top[0])printf("%d ",sta[0][i]);puts("");
            // rep(i,top[1])printf("%d ",sta[1][i]);puts("");
            // printf("%d\n",dis[i]);
        }
        printf("%d\n",dis[n]);
    }
    return 0;
}
/*
5
5
2 1 5 3 4
*/