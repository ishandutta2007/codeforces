#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
int P;
int n,a[N];
int b[N],m;
map<int,int>fp;
int org[N];
int main(){
    srand((int)time(0));
    scanf("%d%d",&P,&n);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,n)org[i]=a[i];
    int on=n;
    int D=0;
    int round=0;
    while(n>100){
        if(clock()>1800){
            printf("-1\n");
            return 0;
        }
        int k=rand()*1ll*rand()%n+1;
        int w=2*a[k]%P;
        fp.clear();
        rep(i,1,n)fp[a[i]]=1;
        m=0;
        rep(i,1,n)if(fp.find((w+P-a[i])%P)==fp.end())b[++m]=a[i];
        n=m;
        rep(i,1,n)a[i]=b[i];
    }
    if(n==1)D=0;
    else{
        D=-1;
        rep(i,2,n){
            fp.clear();
            rep(j,1,n)fp[a[j]]=1;
            int out=0;
            int G=(a[i]-a[1]+P)%P;
            rep(j,1,n)if(fp.find((a[j]+G)%P)==fp.end()){
                if(out!=0)out=-1;
                else out=j;
            }
            if(out==0)out=1;
            if(out!=-1){
                D=G;
                break;
            }
        }
    }
    fp.clear();
    n=on;
    rep(i,1,n)a[i]=org[i];
    if(D==-1){
        printf("-1\n");
        return 0;
    }
    rep(i,1,n)fp[a[i]]=1;
    int out=0;
    rep(j,1,n)if(fp.find((a[j]+P-D)%P)==fp.end()){
        if(out!=0)out=-1;
        else out=j;
    }
    if(out==0)out=1;
    printf("%d %d\n",a[out],D);
    return 0;
}