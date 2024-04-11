#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
int n,x[5],y[5];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=3;i++) scanf("%d%d",&x[i],&y[i]);
    if((x[1]-x[2])*(x[1]-x[3]) < 0) return !printf("NO\n"); 
    if((y[1]-y[2])*(y[1]-y[3]) < 0) return !printf("NO\n");
    printf("YES\n");
}