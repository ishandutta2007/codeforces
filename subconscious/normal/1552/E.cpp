#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
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
typedef pair<int,int> pr;
const int N=100+5,inf=1e9+7;
int n,k,a[N*N],b[N][N],tmp[N];
bool in[N];
int q[N],ind;
bool cmp(int x,int y){return b[x][ind]<b[y][ind];}
bool cp2(pr x,pr y){return a[x.st]<a[y.st];}
vector<pr>vec;
int main(){
    scanf("%d%d",&n,&k);
    rep(i,n*k){
        scanf("%d",a+i);
        b[a[i]][++tmp[a[i]]]=i;
    }
    int cnt=n/(k-1)+(n%(k-1)!=0);
    rep(tim,k-1){
        rep(i,n)q[i]=i;
        ind=tim+1;
        sort(q+1,q+n+1,cmp);
        int tot=0;
        rep(i,n){
            int x=q[i];
            if(!in[x]){
                in[x]=1;
                vec.pb(mp(b[x][tim],b[x][tim+1]));
                ++tot;
                if(tot==cnt)break;
            }
        }
        if(tim*cnt>=n)break;
    }
    sort(vec.begin(),vec.end(),cp2);
    for(pr p:vec)printf("%d %d\n",p.st,p.nd);
    return 0;
}