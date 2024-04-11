#include <cstdio>
using namespace std;

int t, n;

int main(){
    scanf("%d", &t);
    while(t--){
        int used[10] = {};
        scanf("%d", &n);
        while(n--){
            int x;
            scanf("%d", &x);
            used[x] = true;
        }
        int ans = 0;
        for (int i = 0; i < 9; i++)
            if(!used[i])
                for (int j = i + 1; j <= 9; j++)
                    if(!used[j])
                        ans += 6;
        printf("%d\n", ans);
    }
    return 0;
}