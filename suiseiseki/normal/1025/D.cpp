#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool can[705][705];
int a[705];
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int n;
int f[705][705][2];
int dfs(int left,int right,int l_r){
    if(f[left][right][l_r]!=-1){
        return f[left][right][l_r];
    }
    if(left>right){
        return 1;
    }
    int get_ans=0;
    int x;
    if(l_r==0){
        x=left-1;
    }
    else{
        x=right+1;
    }
    for(int i=left;i<=right&&get_ans==0;i++){
        if(can[i][x]){
            if(dfs(left,i-1,1)==1&&dfs(i+1,right,0)==1){
                get_ans=1;
            }
        }
    }
    return f[left][right][l_r]=get_ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(gcd(a[i],a[j])!=1){
                can[i][j]=can[j][i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        can[0][i]=can[i][0]=1;
    }
    memset(f,-1,sizeof f);
    if(dfs(1,n,0)){
        puts("Yes");
    }
    else{
        puts("No");
    }
    return 0;
}