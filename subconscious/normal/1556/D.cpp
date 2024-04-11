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
typedef vector<int> vi;
const int N=1e6+5,mod=1e9+7;
int a12,a23,a31,o12,o23,o31;
int a[N],k,n;
//int t[N];

int aor(int i,int j){
    printf("or %d %d\n",i,j);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    //ret=t[i]|t[j];
    return ret;
}
int aand(int i,int j){
    printf("and %d %d\n",i,j);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    //ret=t[i]&t[j];
    return ret;
}
int main(){
    scanf("%d%d",&n,&k);

    //rep(i,n)scanf("%d",t+i);


    a12=aand(1,2);
    o12=aor(1,2);
    a23=aand(2,3);
    o23=aor(2,3);
    a31=aand(3,1);
    o31=aor(3,1);
    for(int i=0;i<=30;++i){
        int t=1<<i;
        if((a12&t)==(o12&t)){
            a[1]|=(a12&t);
            a[2]|=(a12&t);
            if((a23&t)==(o23&t))
                a[3]|=(a12&t);
            else
                a[3]|=(a12&t)^t;
        }else 
        if((a23&t)==(o23&t)){
            a[2]|=(a23&t);
            a[3]|=(a23&t);
            if((a31&t)==(o31&t))
                a[1]|=(a23&t);
            else
                a[1]|=(a23&t)^t;
        }else
        if((a31&t)==(o31&t)){
            a[3]|=(a31&t);
            a[1]|=(a31&t);
            if((a12&t)==(o12&t))
                a[2]|=(a31&t);
            else
                a[2]|=(a31&t)^t;
        }
    }
    for(int i=4;i<=n;++i){
        int an=aand(1,i),ao=aor(1,i);
        a[i]=a[1]^(an^ao);
    }

    //rep(i,n)printf("%d%c",a[i]," \n"[i==n]);

    sort(a+1,a+n+1);
    int ans=a[k];
    printf("finish %d\n",ans);
    fflush(stdout);
    return 0;
}
/*
7 6
1 6 4 2 3 5 4

*/