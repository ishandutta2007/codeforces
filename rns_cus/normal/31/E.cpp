#include <stdio.h>

#define N 20
typedef __int64 ll;
ll s[2*N][N], p[N];
int f[2*N][N], n, a[2*N];
char A[2*N];
int main(){
///    freopen("in.txt", "r", stdin);
    scanf("%d",&n);
    scanf("%s",A);
    p[0]=1;
    for(int i=1; i<n; i++)p[i]=p[i-1]*10;
    for(int i=0; i<2*n; i++)a[i]=A[i]-'0';
    for(int i=1; i<=2*n; i++){
        for(int j=0; j<=i && j<=n; j++){
            s[i][j]=-1;
            if(j>0)s[i][j]=s[i-1][j-1]+p[j-1]*a[2*n-i];
            if(j<i && s[i][j]<s[i-1][j]+p[i-1-j]*a[2*n-i]){
                s[i][j]=s[i-1][j]+p[i-1-j]*a[2*n-i];
                f[i][j]=1;
            }
        }
    }
    int j=n;
    for(int i=2*n; i>=1; i--){
        printf("%c",f[i][j]?'M':'H');
        if(f[i][j]==0)j--;
    }
    puts("");


    return 0;
}