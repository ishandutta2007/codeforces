#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuckcjb
#define y0 fuckjsb
#define x1 fucklgl
#define y1 fucklyw
#define eb emplace_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=2e6+5,mod=1e9+7;
const ld eps=1e-12;
pr pa[N], pb[N];
ll ans[N];
int op[N];
int m, n;
void add(int l,int r,ll x){
    if(l<=r){
        ans[l]+=x;
        ans[r + 1]-=x;
    }
}
void addx(int i,int l,int r,ll x){
    if(l<=r){
        if(i<l)add(l-i+1,r-i+1,x);
        else if(i>r)add(l+n-i+1,r+n-i+1,x);
        else{
            add(1,r-i+1,x);
            add(l+n-i+1,n,x);
        }
    }
}
void addy(int i,int l,int r,ll x){
    if(l<=r){
        if(i<l)add(i+n-r+1,i+n-l+1,x);
        else if(i>r)add(i-r+1,i-l+1,x);
        else{
            add(1,i-l+1,x);
            add(i+n-r+1,n,x);
        }
    }
}
int main(){
    scanf("%d%d",&m,&n);
    rep(i,n)scanf("%d",&pa[i].st),pa[i].nd=i;
    rep(i,n)scanf("%d",&pb[i].st),pb[i].nd=i;
    sort(pa+1,pa+n+1);
    sort(pb+1,pb+n+1);
    int l,r;
    rep(i,n){
        l=1;
        r=lower_bound(pb+1,pb+n+1,mp(pa[i].st-(m+1)/2,n+1))-pb-1;
        addx(i,l,r,m-pa[i].st);
        l=lower_bound(pb+1,pb+n+1,mp(pa[i].st-(m+1)/2,n+1))-pb;
        r=lower_bound(pb+1,pb+n+1,mp(pa[i].st, n+1)) - pb- 1;
        addx(i,l,r,pa[i].st);
        l=lower_bound(pb + 1, pb + n + 1, mp(pa[i].st, n+1)) - pb;
        r=lower_bound(pb + 1, pb + n + 1, mp(pa[i].st + m / 2, n+1)) - pb - 1;
        addx(i, l, r, -pa[i].st);
        l=lower_bound(pb + 1, pb + n + 1, mp(pa[i].st + m / 2, n+1)) - pb;
        r=n;
        addx(i, l, r, m + pa[i].st);
    }
    rep(i,n){
        l = lower_bound(pa + 1, pa + n + 1, mp(pb[i].st + (m + 1) / 2, 0)) - pa;
        r = n;
        addy(i, l, r,  pb[i].st);
        l = lower_bound(pa + 1, pa + n + 1, mp(pb[i].st, 0)) - pa;
        r = lower_bound(pa + 1, pa + n + 1, mp(pb[i].st + (m + 1) / 2, 0)) - pa - 1;
        addy(i, l, r, -pb[i].st);
        l = lower_bound(pa + 1, pa + n + 1, mp(pb[i].st - m / 2, 0)) - pa;
        r = lower_bound(pa + 1, pa + n + 1, mp(pb[i].st, 0)) - pa - 1;
        addy(i, l, r, pb[i].st);
        l = 1;
        r = lower_bound(pa + 1, pa + n + 1, mp(pb[i].st - m / 2, 0)) - pa - 1;
        addy(i, l, r, -pb[i].st);
    }
    ll mi = 1e18, ss = 0;
    rep(i,n){
        ans[i]+=ans[i-1];
        if(ans[i]<mi)mi=ans[i],ss=i;
    }
    rep(i,n){
        int x=i+ss-1;
        if(x>n)x-=n;
        op[pa[i].nd]=pb[x].nd;
    }
    printf("%lld\n",mi);
    rep(i,n)printf("%d%c",op[i]," \n"[i==n]);
    return 0;
}