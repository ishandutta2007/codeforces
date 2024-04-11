#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define mp make_pair
#define pb push_back
#define x0 fuckcjb
#define y0 fuckjsb
#define x1 fucklbn
#define y1 fuckyzc
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const ld eps=1e-10,inf=1e50;
const int mod=1e9+7,N=3e5+5;
int n;
multiset<pair<int,pr>>st;
int mi,cnt,ans,anscnt,mx;
int main(){
    scanf("%d",&n);
    mi=0,cnt=1;mx=0;
    ans=mod+1,anscnt=0;
    rep(i,n){
        int x,y;scanf("%d%d",&x,&y);
        st.insert(mp(y,mp(x,mod+1)));
        mx=max(mx,y);
    }
    while(st.size()>0){
        pair<int,pr> p=*st.begin();st.erase(st.begin());
        //printf("%d %d %d\n",p.st,p.nd.st,p.nd.nd);
        if(p.nd.nd!=mod+1){
            if(p.nd.st<mi)mi=p.nd.st,cnt=p.nd.nd;
            else if(p.nd.st==mi)cnt=(cnt+p.nd.nd)%mod;
        }else{
            int nw=mi+p.st-p.nd.st;
            st.insert(mp(p.nd.st,mp(nw,cnt)));
            if(p.nd.st>mx){
                if(nw+p.nd.st<ans)ans=nw+p.nd.st,anscnt=cnt;
                else if(nw+p.nd.st==ans)anscnt=(anscnt+cnt)%mod;
            }
        }

    }
    printf("%d\n",anscnt);
    return 0;
}