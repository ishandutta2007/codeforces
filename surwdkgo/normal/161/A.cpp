#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,x,y, a[100010], b[100010], ans[100010][2], anl;
int main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<m;i++)scanf("%d",&b[i]);
    int cur = 0;
    for(int i=0;i<n;i++){
        while(cur<m && b[cur]<a[i]-x)cur++;   
        if(cur<m && b[cur]<=a[i]+y){
            ans[anl][0]=i+1;
            ans[anl][1]=cur+1;
            anl++;
            cur++;   
        }
    }
    printf("%d\n",anl);
    for(int i=0;i<anl;i++)printf("%d %d\n", ans[i][0], ans[i][1]);
    scanf(" ");
    return 0;
}