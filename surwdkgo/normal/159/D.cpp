#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char inp[2010],pal[2010][2010];
int n;
long long lef[2010], rig[2010];
int main(){
    scanf("%s", inp);
    n = strlen(inp);
    for(int i=0;i<n;i++){
        pal[i][i] = 1;
        pal[i][i+1] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            if(inp[j]==inp[i+j-1])pal[j][i+j] = pal[j+1][i+j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(pal[i][j]){
                lef[j]++;
                rig[i]++;   
            }
        }
    }
    long long ans =0 ;
    for(int i=n-1;i>=0;i--){
        rig[i]+=rig[i+1];
        ans+=rig[i]*lef[i];
    }
    printf("%I64d\n", ans);
    scanf(" ");
    return 0;
}