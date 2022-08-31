#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=510000;
int n;
int main(){
    scanf("%d",&n);
    printf("YES\n");
    while(n--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1=abs(x1);y1=abs(y1);
        printf("%d\n",(x1%2)*2+(y1%2)+1);
    }
    return 0;
}