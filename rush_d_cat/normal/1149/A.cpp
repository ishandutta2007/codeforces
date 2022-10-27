#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n,a[N],c[3];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1) c[1]++;
        else c[2]++;
    }

    if(c[1]==n) {
        for(int i=1;i<=n;i++){
            printf("1 ");
        }
        return 0;
    }
    if(c[2]==n) {
        for(int i=1;i<=n;i++){
            printf("2 ");
        }
        return 0;        
    }

    printf("2 "); c[2]--;
    printf("1 "); c[1]--;
    for(int i=1;i<=c[2];i++) printf("2 ");
    for(int i=1;i<=c[1];i++) printf("1 ");
}