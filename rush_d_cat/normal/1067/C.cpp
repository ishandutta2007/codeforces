#include <iostream>
using namespace std;
int n;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int main(){
    cin>>n;
    printf("0 0\n");
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(i%4==2) cnt++;
        printf("%d %d\n", cnt*dx[i%4],cnt*dy[i%4]);
    }
}