///c
#include<stdio.h>

#define N 111

char g[N][N],tile[2][2][2]={'a','b','c','d','e','f','g','h'};

void print(int n,int m){
    for(int i=0;i<n;i++)
        puts(g[i]);
}
int solve(int n,int m,int a,int b,int c)
{
    if(a<0 || b<0)return 0;
    char t1='i',t2='j';
    if(n%2&&m%2)return 0;
    if(n%2) {
        int k=solve(n-1,m,a-m/2,b,c);
        for(int i=0;i<m;i+=2){
            int ii=i/2;
            if(ii%2==0)g[n-1][i]=g[n-1][i+1]=t1;
            else g[n-1][i]=g[n-1][i+1]=t2;
        }
        return k;
    }
    if(m%2) {
        int k=solve(n,m-1,a,b-n/2,c);
        for(int i=0;i<n;i+=2){
            int ii=i/2;
            if(ii%2==0)g[i][m-1]=g[i+1][m-1]=t1;
            else g[i][m-1]=g[i+1][m-1]=t2;
        }
        return k;
    }
    a-=a%2;
    b-=b%2;
    if(n*m>a*2+b*2+c*4)return 0;
    for(int i=0;i<n;i+=2){
        for(int j=0;j<m;j+=2){
            int ii=i/2,jj=j/2;
            t1=tile[ii%2][jj%2][0],t2=tile[ii%2][jj%2][1];
            if(c){
                c--;
                g[i][j]=g[i][j+1]=g[i+1][j]=g[i+1][j+1]=t1;
                continue;
            }
            if(a){
                a-=2;
                g[i][j]=g[i][j+1]=t1;
                g[i+1][j]=g[i+1][j+1]=t2;
                continue;
            }
            b-=2;
            g[i][j]=g[i+1][j]=t1;
            g[i][j+1]=g[i+1][j+1]=t2;
        }
    }
    return 1;
}

int main()
{
  ///  freopen("in.txt","r",stdin);
   /// freopen("ou.txt","w",stdout);
    int n,m,a,b,c;
    scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
    if(!solve(n,m,a,b,c))puts("IMPOSSIBLE");
    else print(n,m);
    return 0;
}