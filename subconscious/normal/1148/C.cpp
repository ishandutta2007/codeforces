#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define st first
#define nd second
#define x0 fuckcjb
#define y0 fuckjsb
#define x1 fucklgl
#define y1 fucklyw
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,mod=1e9+7;
const ld eps=1e-12;
int a[N],pos[N],n;
vector<pr>ans;
void swp(int x,int y){
    if(abs(x-y)*2>=n){ans.pb({x,y});return;}
    ans.pb({x,(x<=n/2?n:1)});
    ans.pb({y,(y<=n/2?n:1)});
    if((x<=n/2?n:1)!=(y<=n/2?n:1)){
        ans.pb({1,n});
        ans.pb({x,(x<=n/2?n:1)});
        ans.pb({y,(y<=n/2?n:1)});
    }else{
        ans.pb({x,(x<=n/2?n:1)});
    }
}
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i),pos[a[i]]=i;
    rep(i,n)if(pos[i]!=i){
        int x=a[pos[i]],y=a[i];
        swp(pos[i],i);
        swap(a[pos[i]],a[i]);
        swap(pos[x],pos[y]);
    }
    printf("%d\n",(int)ans.size());
    for(pr p:ans)printf("%d %d\n",p.st,p.nd);
}