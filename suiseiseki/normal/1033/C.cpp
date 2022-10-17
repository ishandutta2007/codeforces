#include <cstdio>
#include <cstring>
int a[100005],f[100005];
int n;
int dfs(int x){
    if(f[x]!=-1){
        return f[x];
    }
    f[x]=0;
    for(int i=x+a[x];i<=n;i+=a[x]){
        if(a[x]<a[i]){
            if(dfs(i)==0){
                f[x]=1;
                break;
            }
        }
    }
    if(f[x]==1){
        return f[x];
    }
    for(int i=x-a[x];i>0;i-=a[x]){
        if(a[x]<a[i]){
            if(dfs(i)==0){
                f[x]=1;
                break;
            }
        }
    }
    return f[x];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    memset(f,-1,sizeof f);
    for(int i=1;i<=n;i++){
        if(dfs(i)==0){
            putchar('B');
        }
        else{
            putchar('A');
        }
    }
    puts("");
    return 0;
}