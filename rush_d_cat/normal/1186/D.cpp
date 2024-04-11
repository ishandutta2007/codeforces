#include <iostream>
#include <cmath>
using namespace std;
const int N = 100002;
typedef long long LL;

int down(double x) {
    if(abs(x-(int)x) < 1e-7) return (int) x;
    if(x>=0) return (int)x;
    return ((int)x)-1;
}

int n;
double a[N];
int x[N];
int main() {
    scanf("%d",&n);
    LL sum = 0;
    for(int i=1;i<=n;i++) {
        scanf("%lf",&a[i]);
        x[i] = down(a[i]);
        sum += x[i];
    }
    
    for(int i=1;i<=n;i++) {
        if(sum<0) {
            if(a[i] != (int)a[i]) {
                sum++;
                x[i]++;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
        printf("%d\n", x[i]);
}