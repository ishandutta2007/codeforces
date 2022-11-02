#include<bits/stdc++.h>
using namespace std;
char a;
main(){
    int n,m,r1= 10000,r2=0,c1 = 10000,c2 = 0,cnt = 0;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n ; i++)
    for(int j = 1; j <= m ; j++){
        scanf("\n%c",&a);
        if(a == 'B'){
                r1 = min(r1,i);
                r2 = max(r2,i);
                c1 = min(c1,j);
                c2 = max(c2,j);
                cnt ++;
        }
    }
    if(!r2) {puts("1");return 0;}
    int c = max(r2 - r1,c2 -c1)+1;
    if(c > m || c > n) {puts("-1");return 0;}
    printf("%d\n",c*c - cnt);
}