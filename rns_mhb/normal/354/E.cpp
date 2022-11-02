#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
#define pb push_back
#define sz size()
#define clr(u) memset(u, 0, sizeof(u))
typedef long long ll;
struct str{
    ll a[7];
    str(){};
    str(ll b[]){
        for(int i=0; i<7; i++)a[i]=b[i];
    }
    str operator+(str x){
        str u;
        for(int i=0; i<7; i++)u.a[i]=x.a[i]+a[i];
        return u;
    }
    str operator*(ll x){
        str u;
        for(int i=0; i<7; i++)u.a[i]=a[i]*x;
        return u;
    }
};

vector<str> v[100];
ll n;

void init(){
    int i, x, y, z, ans;
    for(x=0; x<=6; x++)for(y=0; y<=6-x; y++){
        z=6-x-y;
        ans = x*7 + y*4;
        str t;
        for(i=0; i<x; i++)t.a[i]=7;
        for(i=0; i<y; i++)t.a[i+x]=4;
        for(i=0; i<z; i++)t.a[i+x+y]=0;
        v[ans].pb(t);
    }
/*  for(i=0; i<=42; i++){
        printf("I = %d\n", i);
        for(int j=0; j<v[i].sz; j++){
            for(int k=0; k<6; k++)printf("%I64d ", v[i][j].a[k]);puts("");
        }
    }*/
}
bool ok;
str solve(ll n){
    int i, j, k;
    if(!n){
        ok=1;
        str tmp;
        for(i=0; i<7; i++)tmp.a[i]=0;
        return tmp;
    }
    str tmp;
    ll nn;
    for(ll u=n%10; u<50 and u<=n; u+=10)if(v[u].sz>0){
        for(k=0; k<v[u].sz; k++){
            tmp=v[u][k];
            nn=(n-u)/10;
            str aft=solve(nn);
            if(ok)return aft*10+tmp;
        }
    }
}

int main(){
    init();
    ///freopen("B.in", "r", stdin);
    int k, T;
    for(scanf("%d", &T); T--; ){
        scanf("%I64d", &n);
        ok=0;
        str ans=solve(n);
        if(ok){
            for(k=0; k<6; k++)printf("%I64d%c", ans.a[k], k==5?10:32);
        }else{
            puts("-1");
        }
    }
    return 0;
}