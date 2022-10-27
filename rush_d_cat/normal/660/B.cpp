#include<iostream>
using namespace std;
bool used[400+10];
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=4*m;i++){
        used[i]=(i<=n);
    }
    int cnt=0;
    int tmp=2*m+1;
    for(int i=1;i<=n;i++){
        if(used[tmp]){
            printf("%d ",tmp);
            cnt++;
        }
        if(used[tmp-2*m]){
            printf("%d ",tmp-2*m);
            cnt++;
        }
        tmp++;
        if(tmp>4*m) break;
    }
    printf("\n");
    return 0;
}