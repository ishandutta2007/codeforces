#include <iostream>
using namespace std;
const int N=100000+10;
int n,k,a[N];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int now=0;
    for(int i=1;i<=n;i++){
        if(k<=now+i && k>=now+1) {
            return !printf("%d\n", a[k-now]);
        }
        now+=i;
    }
}