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
const double eps=1e-9;
const int N=(int)1.5e5+5;
struct num{
    int x,y;
    int typ()const{return y<0?-1:y>0;}
    void scan(){scanf("%d%d",&x,&y);}
}a[N];
bool cmp(num a,num b){
    if(a.typ()!=b.typ())return a.typ()>b.typ();
    if(a.typ()==-1){
        //a.x==b.x a.y>b.y
        //a.y==b.y a.x>b.x
        return a.x+a.y>b.x+b.y;
    }else if(a.typ()==1){
        return a.x<b.x;
    }else return 0;
}
int n,r;
bool check(){
    int now=r;
    rep(i,n){
        if(now<a[i].x)return 0;
        now+=a[i].y;
        if(now<0)return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&r);
    rep(i,n)a[i].scan();
    sort(a+1,a+n+1,cmp);
    puts(check()?"YES":"NO");
    return 0;
}