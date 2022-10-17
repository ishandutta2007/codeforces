#include <cstdio>
int a[105];
int n;
bool check(int x){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum>x){
            return 0;
        }
        if(sum==x){
            sum=0;
        }
    }
    if(x==0){
        return 1;
    }
    if(x!=0&&sum>0){
        return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++){
        scanf("%1d",&a[i]);
        sum+=a[i];
    }
    if(sum==0){
        sum++;
    }
    for(int i=0;i<sum;i++){
        if(check(i)){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}