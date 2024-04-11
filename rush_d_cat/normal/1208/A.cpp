#include <iostream>
using namespace std;
int T,a,b,n;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d",&a,&b,&n);
        int ans=0;
        for(int i=0;i<=31;i++){
            int x1 = a>>i&1;
            int x2 = b>>i&1;
            if(x1==0&&x2==1) {
                if(n%3) ans|=1<<i;
            }
            if(x1==1&&x2==0){
                if(n%3!=1) ans|=1<<i;
            }
            if(x1==1&&x2==1){
                if(n%3!=2) ans|=1<<i;
            }
        }
        printf("%d\n", ans);
    }
}
/*
000000
0110110110
10110110
110110110
*/