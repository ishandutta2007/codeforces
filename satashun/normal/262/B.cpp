#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
 
int n, k;
int a[100010];
int cnt, sum;
 
int main(){
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] < 0) cnt++;
        sum += a[i];
    }
    int idx = 0;
    while(cnt > 0 && k > 0 && idx < n){
        cnt--;
        a[idx] *= -1;
        sum += 2 * a[idx++];
        k--;
    }
    if(!(k & 1)){
        printf("%d\n", sum);
        return 0;
    }
    sort(a, a + n);
    printf("%d\n", sum - a[0] * 2);
    return 0;
}