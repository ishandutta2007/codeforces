#include <iostream>
using namespace std;
const int N = 200000 + 10;

int n,a[N];
int sum[N];
void solve(int x) {
    int nex=0; x=x-2;
    for(int i=1;i<=x;i=nex+1){
        nex=x/(x/i);
        // [i,nex]
        if(a[x/i + 1] > a[x+2]) sum[i] ++, sum[nex+1]--;
        //printf("%d root=%d [%d,%d]\n", x+2,x/i+1,i,nex);
    }
    if (a[1] > a[x+2]) {
        //printf("! %d root=%d, [%d,%d]\n", x+2,1,nex+1,n-1);
        sum[nex+1] ++, sum[n] --; 
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) {
        solve(i);
    }
    for(int i=1;i<n;i++) sum[i] += sum[i-1], printf("%d ", sum[i]);
}