#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n,a[N],b[N],p[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[a[i]]=i;
    int top=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        if(p[b[i]]>top) {
            printf("%d ", p[b[i]]-top); top=p[b[i]];
        } else {
            printf("0 ");
        }
    }
    printf("\n");
}