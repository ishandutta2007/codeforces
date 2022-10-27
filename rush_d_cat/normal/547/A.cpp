#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=10000000+10;
LL m;
LL h1,a1,x1,y1;
LL h2,a2,x2,y2;

LL exgcd(LL a, LL b, LL& x, LL& y)  {  
    if(!b) {  
        x = 1; y = 0; return a;  
    }  
    LL r = exgcd(b,a%b,y,x);  
    y -= a/b*x;  
    return r;  
}  
LL mabs(LL x){
    return x<0?-x:x;
}
bool vis[N];

LL H1[N],H2[N];
int main(){
    cin>>m;
    cin>>h1>>a1>>x1>>y1;
    cin>>h2>>a2>>x2>>y2;
    int A=1000000;
    for(int i=1;i<=A;i++){
        h1=(x1*h1+y1)%m; 
        h2=(x2*h2+y2)%m; 
        if(h1==a1 && h2==a2)return !printf("%d\n",i);
    }
    
    /*
    while(1){
        int x; cin>>x;
        cout<<H1[x]<<" "<<H2[x]<<endl;
    }
    */
    int ans=A;
    // k1*x1+b1 = k2*x2+b2
    // k1*x1 - k2*x2 = b2 - b1
    memset(vis,0,sizeof(vis));
    
    LL k1=0,b1=-1,k2=0,b2=-1;
    for(int i=1;i<N;i++){
        if(vis[h1])break;
        vis[h1]=1;
        if(h1==a1)b1=k1;
        k1++;
        h1=(x1*h1+y1)%m;
    }

    memset(vis,0,sizeof(vis));
    for(int i=1;i<N;i++){
        if(vis[h2]){
            break;
        }
        vis[h2]=1;
        if(h2==a2)b2=k2;
        k2++;
        h2=(x2*h2+y2)%m;
    }
    //printf("%lld %lld %lld %lld\n", k1,b1,k2,b2);
    if(b1==-1||b2==-1)return !printf("-1\n");

    LL x,y;
    LL g=exgcd(k1,-k2,x,y);
    //printf("g=%lld\n", g);
    if((b2-b1)%g)return !printf("-1\n");
    x *= (b2-b1)/g; LL dx = mabs(k2/g);
    y *= (b2-b1)/g; LL dy = mabs(k1/g);
    while(x<0) {
        x += dx, y += dy;
    }
    while(y<0) {
        y += dy, x += dx;
    }
    LL lim = min(x / dx, y / dy);
    x -= lim * dx;
    printf("%lld\n", ans + k1*x+b1);
}