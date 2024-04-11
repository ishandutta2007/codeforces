#include <cstdio>
using namespace std;
 
int n, k;
int ans;
 
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        int tmp;
        int cnt = 0;
        scanf("%d", &tmp);
        while(tmp > 0){
            if(tmp % 10 == 4 || tmp % 10 == 7) cnt++;
            tmp /= 10;
        }
        if(cnt <= k) ans++;
    }
    printf("%d\n", ans);
    return 0;
}