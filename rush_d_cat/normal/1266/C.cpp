#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=500+10;
typedef long long LL;
int r,c,a[N][N];
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main() {
    cin>>r>>c;
    if(r==1 && c==1) {
        return !printf("0\n");
    }
    if(r>1 && c==1) {
        for(int i=2;i<=r+1;i++){
            printf("%d\n", i);
        }
        return 0;
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++) a[i][j]=i;
    }
    int k=r;
    for(int j=1;j<=c;j++){
        ++ k;
        for(int i=1;i<=r;i++){
            a[i][j] *= k;
            //printf("%d ", a[i][j]);
        }
        //printf("\n");
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}