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
int n;
struct node{
    int x,y,k;
};
vector<node>a,b;
bool cmpa(node x,node y){return x.y>y.y;}
bool cmpb(node x,node y){return x.x<y.x;}
int main(){
    scanf("%d",&n);
    rep(i,n){
        int x,y;scanf("%d%d",&x,&y);
        if(x<y)a.pb({x,y,i});
        if(x>y)b.pb({x,y,i});
    }
    sort(a.begin(),a.end(),cmpa);
    sort(b.begin(),b.end(),cmpb);
    if(a.size()>b.size()){
        printf("%d\n",(int)a.size());
        for(node p:a)printf("%d ",p.k);
            puts("");
    }else{
        printf("%d\n",(int)b.size());
        for(node p:b)printf("%d ",p.k);
            puts("");

    }
}