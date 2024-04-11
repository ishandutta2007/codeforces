#include<bits/stdc++.h>
using namespace std;
int la,la1;
void mo(int x, int y){
    printf("%d %d\n",x,y);
}
main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n/2; i++){
        for(int j = 1; j <= m; j++)
            mo(i,j),
            mo(n+1-i, m+1-j);

    }
    if(n % 2 == 1)
        for(int j = 1; j <= m/ 2; j++)
            mo(n/2+1,j),
            mo(n/2+1,m+1-j);
    if(m % 2== 1 && n % 2==1) mo(n/2+1,m/2+1);
}