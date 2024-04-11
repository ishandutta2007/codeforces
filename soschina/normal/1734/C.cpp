#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 2;

int t, n;
char s[N];
bool cleared[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%s", &n, s + 1);
        memset(cleared + 1, 0, sizeof(bool) * n);
        long long ans = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i; j <= n; j += i)
                if(s[j] == '0'){
                    if(!cleared[j]){
                        ans += i;
                        cleared[j] = true;
                    }
                }
                else if(!cleared[j])
                    break;
        }
        printf("%lld\n", ans);
    }
    return 0;
}