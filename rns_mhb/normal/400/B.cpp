#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 1001
#define M 1001
using namespace std;
char s[N][M];
int c[N];
int ans,mm;
int main(){
    int i,j,n,m;
  //  freopen("in.txt","r",stdin);
    scanf("%d%d\n",&n,&m);
    for(i=0;i<n;i++){
            gets(s[i]);
            for(j=0;j<strlen(s[i]);j++){
                    if(s[i][j]=='G')c[i]=j+1;
                    if(s[i][j]=='S')c[i]-=j+1;
            }
            if(c[i]>0){printf("%d\n",-1);goto k;}
    }
    sort(c,c+n);
    for(i=1,mm=c[0],ans=1;i<n;i++){
        if(mm!=c[i]){ans++;mm=c[i];}
    }
    printf("%d\n",ans);
    k:;
    return 0;
}