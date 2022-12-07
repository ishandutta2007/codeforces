#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, x;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &x);
        if(x == n){
            printf("%d ", x);
            for (int i = 2; i < n; i++)
                printf("%d ", i);
            printf("1\n");
        }
        else if(n % x)
            puts("-1");
        else{
            int m = n / x;
            vector<int> fac;
            for (int i = 2; i <= m; i++)
                if(m % i == 0){
                    do{
                        fac.push_back(i);
                        m /= i;
                    } while (m % i == 0);
                }
            fac.push_back(1);
            reverse(fac.begin(), fac.end());
            int now = x;
            printf("%d ", x);
            for (int i = 2; i < n; i++){
                if(i == now){
                    int nxt = now * fac.back();
                    fac.pop_back();
                    printf("%d ", nxt);
                    now = nxt;
                }
                else
                    printf("%d ", i);
            }
            printf("1\n");
        }
    }
    return 0;
}