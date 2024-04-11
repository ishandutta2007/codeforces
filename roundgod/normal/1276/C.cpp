#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
const int maxn=4e5+10;
int n,a[maxn],d[maxn],ans[maxn],p,q,tot;
vector <int> b[maxn],Ans;
map <int,int> f;
bool check(int x,int y){return x*y<=d[x];}
int id(int x,int y){return x*q+y;}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        int x;scanf("%d",&x);
        f[x]++;
    }
    for (auto x:f) tot++,b[x.S].pb(x.F);
    tot=0; d[n]=n;
    for (int i=n;i;i--) tot+=b[i].size(),d[i-1]=d[i]-tot;
    for (int i=1;i*i<=n;i++){
        if (!check(i,i)) continue;
        int l=i,r=n/i+1;
        while (r-l>1){
            int mid=(l+r)>>1;
            if (check(i,mid)) l=mid; else r=mid;
        }
        if (p*q<i*l) p=i,q=l;
    }
    int m=p*q;
    for (int i=n;i;i--){
        for (auto x:b[i]){
            int s=min(m,min(p,i));
            for (int j=0;j<s;j++) Ans.pb(x);
            m-=s;
            if (!m) break;
        }
        if (!m) break;
    }
    assert(Ans.size()==p*q);
    for (int i=0;i<p*q;i++)
        ans[id(i%p,((i/p)+(i%p))%q)]=Ans[i];
    printf("%d\n%d %d\n",p*q,p,q);
    for (int i=0;i<p;i++){
        for (int j=0;j<q;j++) printf("%d ",ans[id(i,j)]);
        puts("");
    }
    return 0;
}