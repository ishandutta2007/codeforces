#include <iostream>
#include <cstring>
using namespace std;
const int N = 502;
const int B = 500;
int n,b[N];
int x[N],y[N];
void prt(){
    for(int i=B;i>=1;i--) {
        if(x[i]) {
            for(int j=i;j>=1;j--)
                printf("%d", x[j]);
            printf("\n");
            break;
        }
    }
}
void gen(int lim) {
    int sum=0;
    int las=B;
    for(int i=B;i>=1;i--) {
        for(int j=x[i]+1;j<=9;j++) {
            int nexsum = sum + j;
            if(nexsum > lim || 9*(i-1)<lim-nexsum) continue;
            las = i;
        }
        sum += x[i];
    }

    //printf("las=%d\n", las);
    sum=0;
    for(int i=B;i>las;i--) {
        sum += x[i]; y[i]=x[i];
    }
    //printf("sum=%d\n", sum);
    for(int i=x[las]+1;i<=9;i++) {
        int nexsum = sum + i;
        //printf("i=%d, nexsum=%d\n", i,nexsum);
        if(nexsum > lim || 9*(las-1)<lim-nexsum) continue;
        y[las]=i;
        int rem = lim-nexsum;
        for(int j=1;j<=las-1;j++) {
            if(rem>=9) y[j]=9,rem-=9;
            else y[j]=rem,rem=0;
        }
        break;
    }
    for(int i=1;i<=B;i++) {
        x[i]=y[i];
    }
    prt();
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    int tmp=b[1];
    while(tmp) {
        if(tmp>=9) x[++x[0]]=9, tmp-=9;
        else x[++x[0]]=tmp, tmp=0;
    }
    prt();
    for(int i=2;i<=n;i++) {
        gen(b[i]);
    }

}