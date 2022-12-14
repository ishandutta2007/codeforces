#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,u) for(int i=H[u];i;i=nxt[i])
#define re(i,a,b) for (int i=a;i<b;++i)
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int nmax=345678, mod=1e9+7;
int n, t[4 * nmax], k, q, m, x;
pii rooks[nmax];
pii lq[nmax], rq[nmax];
char ans[nmax];
vector<int>Q[nmax],P[nmax];

int get(int l, int r, int v, int tl, int tr){
    if(tl == l&&r == tr){
        return t[v];
    }
    int tm =(tl+tr)/2;
    if(r<=tm)return get(l,r,2*v,tl,tm);
    if(l>tm)return get(l,r,2*v+1,tm+1,tr);
    return min(get(l,tm,2*v,tl,tm), get(tm+1,r,2*v+1,tm+1,tr));
}

void upd(int p, int z, int v, int l, int r){
    if(l==r){
        t[v]=z;
        return;
    }
    int m=(l+r)/2;
    if(p<=m)upd(p,z,2*v,l,m);
    else upd(p,z,2*v+1,m+1,r);
    t[v]=min(t[2*v],t[2*v+1]);
}

void go() {
    memset(t, 0, sizeof(t));
    rep(i,1,k){
        P[rooks[i].X].pb(rooks[i].Y);
    }
    rep(i,1,q){
        Q[rq[i].X].pb(i);
    }
    rep(i,1,n){
        for(int j=0;j < si(P[i]); ++j){
            upd(P[i][j], i, 1, 1, m);
        }
        for(int j=0;j < si(Q[i]); ++j){
            int d = Q[i][j];
            ans[d] |= (get(lq[d].Y, rq[d].Y, 1, 1, m) >= lq[d].X);
        }
    }
    rep(i,1,n){
        Q[i].clear();
        P[i].clear();
    }
}

int main() {
    //ios :: sync_with_stdio(false);
    read(n, m);
    read(k, q);
    rep(i,1,k)
    read(rooks[i].X, rooks[i].Y);
    rep(i,1,q){
        read(lq[i].X,lq[i].Y);
        read(rq[i].X,rq[i].Y);
    }
    go();
    swap(n,m);
    rep(i,1,k)
    swap(rooks[i].X, rooks[i].Y);
    rep(i,1,q){
        swap(lq[i].X,lq[i].Y);
        swap(rq[i].X,rq[i].Y);
    }
    go();
    rep(i,1,q){
        if(ans[i]){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    cin.get(); cin.get();
	return 0;
}