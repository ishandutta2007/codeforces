#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=1100;
bool f[N][N][2];
pii pre[N][N][2];
char way[N][N][2];
int n,k;
char a[N];
void out(int n,int k,int d){
    if(n==0)return;
    out(n-1,pre[n][k][d].fi,pre[n][k][d].se);
    putchar(way[n][k][d]);
}
void update(int i,int j,int d,pii ww,char ss){
    f[i][j][d]=1;
    pre[i][j][d]=ww;
    way[i][j][d]=ss;
}
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",a+1);
    f[0][0][0]=1;
    rep(i,0,n-1)rep(j,0,k-1)rep(d,0,1)if(f[i][j][d]){
        if(a[i+1]=='W'||a[i+1]=='?'){
            if(j==0)update(i+1,1,1,pii(j,d),'W');
            else if(d==0)update(i+1,j-1,d,pii(j,d),'W');
            else update(i+1,j+1,d,pii(j,d),'W');       
        }
        if(a[i+1]=='D'||a[i+1]=='?'){
            update(i+1,j,d,pii(j,d),'D');
        }
        if(a[i+1]=='L'||a[i+1]=='?'){
            if(j==0)update(i+1,1,0,pii(j,d),'L');
            else if(d==0)update(i+1,j+1,d,pii(j,d),'L');
            else update(i+1,j-1,d,pii(j,d),'L');
        }
    }
    rep(d,0,1)if(f[n][k][d]){
        out(n,k,d);
        putchar('\n');
        return 0;
    }
    puts("NO");
    return 0;
}