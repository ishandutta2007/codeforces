#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const ld eps=1e-9;
const int N=(int)2e6+5,mod=1e9+7;
ll n,p,a[N],q[N];
ll ans[N],tim[N];
set<ll>st,fd;
ll qt[N],l,r;
bool cmp(ll x,ll y){if(a[x]!=a[y])return a[x]<a[y];return x<y;}
ll t[N];
void add(ll p,ll num){for(;p<N;p+=p&-p)t[p]+=num;}
ll que(ll p){ll s=0;for(;p;p-=p&-p)s+=t[p];return s;}
int main(){
    scanf("%lld%lld",&n,&p);
    rep(i,n)scanf("%lld",a+i);
    rep(i,n)q[i]=i;
    sort(q+1,q+n+1,cmp);
    l=1,r=0;
    rep(i,n){
        //printf("now:%d\n",i);
        while(l<=r&&tim[l]+p<=a[q[i]]){
            ll now=tim[l]+p;
            ans[qt[l]]=tim[l]+p;
            add(qt[l],-1);
            fd.erase(qt[l]);++l;
            {
                ll tmp;
                if(fd.size())tmp=*fd.begin();else tmp=n+1;
                if(st.size()){
                    ll tmp2=*st.begin();
                    if(tmp2<tmp){
                        if(now==a[q[i]]&&que(q[i])==0&&q[i]<tmp2)continue;
                       // printf("gen2:%d\n",tmp2);
                        st.erase(tmp2);
                        add(tmp2,1);
                        qt[++r]=tmp2;
                        tim[r]=now;
                        if(l<r)tim[r]=max(tim[r],tim[r-1]+p);
                        fd.insert(tmp2);
                    }
                }
            }
        }
        ll to=q[i];
        if(que(to)==0){
            //            printf("gen1:%d\n",to);
            add(to,1);
            qt[++r]=to;
            tim[r]=a[to];
                        if(l<r)tim[r]=max(tim[r],tim[r-1]+p);
            fd.insert(to);
        }else st.insert(to);
    }
    while(l<=r){
            ans[qt[l]]=tim[l]+p;ll now=tim[l]+p;
            add(qt[l],-1);
            fd.erase(qt[l]);++l;
            {
                ll tmp;
                if(fd.size())tmp=*fd.begin();else tmp=n+1;
                if(st.size()){
                    ll tmp2=*st.begin();
                    if(tmp2<tmp){
                        st.erase(tmp2);
                        add(tmp2,1);
                        qt[++r]=tmp2;
                        tim[r]=now;
                        if(l<r)tim[r]=max(tim[r],tim[r-1]+p);
                        fd.insert(tmp2);
                    }
                }
            }
    }
    rep(i,n)printf("%lld%c",ans[i]," \n"[i==n]);
    return 0;
}