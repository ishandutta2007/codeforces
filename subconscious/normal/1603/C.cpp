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
typedef pair<int,int> pr;
const int N=1e5+5,mod=998244353;
const ld PI=acos(-1),eps=1e-12;
int a[N],n,T,ans;
vector<pair<int,pair<int,int>>>sta,tmp;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        // n=4;
        // rep(i,n)a[i]=n-i+1;
        reverse(a+1,a+n+1);
        ans=0;
        sta.clear();sta.pb(mp(N,mp(1,0)));
        rep(i,n){
            int ptr=0;
            tmp.clear();tmp.pb(mp(N,mp(1,0)));
            for(int j=1,k;j<=a[i];j=k+1){
                k=a[i]/(a[i]/j);
                if(j<k&&a[i]%k==0)--k;
                //printf("%d %d %d\n",a[i],j,k);
                int low=a[i]/j,high=a[i]/j+(a[i]%j!=0);
                //while(ptr+1<sta.size()&&sta[ptr+1].st>=high)++ptr;
                while(ptr<sta.size()&&sta[ptr].st>=high){
                    tmp.pb(mp(low,mp(sta[ptr].nd.st,(sta[ptr].nd.nd+(ll)sta[ptr].nd.st*(j-1))%mod)));
                    ++ptr;
                }
            }
            int top=1;
            for(int j=1,mx=tmp.size();j<mx;++j)
                if(tmp[top-1].st==tmp[j].st){
                    tmp[top-1].nd.st=(tmp[top-1].nd.st+tmp[j].nd.st)%mod;
                    tmp[top-1].nd.nd=(tmp[top-1].nd.nd+tmp[j].nd.nd)%mod;
                }else tmp[top++]=tmp[j];
            tmp.resize(top);
            
            // for(int j=0,mx=tmp.size();j<mx;++j)
            //     printf("%d %d %d %d\n",a[i],tmp[j].st,tmp[j].nd.st,tmp[j].nd.nd);
            
            for(int j=0,mx=tmp.size();j<mx;++j)
                ans=(ans+tmp[j].nd.nd)%mod;
            swap(tmp,sta);
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
1.000000 -12.904762 40.476190 -28.571429
3.000000 11.607143 -34.424603 22.817460
*/