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
const int N=2025,mod=998244353;
int a[N],n,m,T;
vector<int>ans;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        bool flag=0;
        for(int i=1;i<=n;i+=2)if(a[i]%2==0){flag=1;break;}
        if(flag){puts("-1");continue;}
        ans.clear();
        for(int i=n;i>1;i-=2){
            int j=i-1;
            int pi,pj;
            rep(k,i)if(a[k]==i)pi=k;else if(a[k]==j)pj=k;
            if(pi!=pj-1){
                ans.pb(pi);
                reverse(a+1,a+pi+1);
                rep(k,i)if(a[k]==i)pi=k;else if(a[k]==j)pj=k;
                
                ans.pb(pj-1);
                reverse(a+1,a+pj-1+1);
                rep(k,i)if(a[k]==i)pi=k;else if(a[k]==j)pj=k;
            }
            ans.pb(pj+1);
            reverse(a+1,a+pj+1+1);
            rep(k,i)if(a[k]==i)pi=k;else if(a[k]==j)pj=k;

            ans.pb(3);
            reverse(a+1,a+3+1);
            rep(k,i)if(a[k]==i)pi=k;else if(a[k]==j)pj=k;

            ans.pb(i);
            reverse(a+1,a+i+1);
            rep(k,i)if(a[k]==i)pi=k;else if(a[k]==j)pj=k;
        

        }
        int mx=ans.size();
        printf("%d\n",mx);
        rep(i,mx)printf("%d%c",ans[i-1]," \n"[i==mx]);
        //rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}
/*
    a b
u   i j
v   k p
*/