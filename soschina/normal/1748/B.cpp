#include <cstdio>
#include <set>
using namespace std;
const int N = 1e5 + 2;

int t, n;
char s[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%s", &n, s + 1);
        int ans = 0;
        for (int i = 1; i <= 100 && i <= n; i++){
            int cnt[10] = {}, occur = 0;
            for (int j = 1; j < i; j++){
                if(!cnt[s[j] - '0'])
                    occur++;
                ++cnt[s[j] - '0'];
            }
            for (int j = i; j <= n; j++){
                if(!cnt[s[j] - '0'])
                    occur++;
                cnt[s[j] - '0']++;
                int maxcnt = 0;
                for (int k = 0; k < 10; k++)
                    if(cnt[k] > maxcnt)
                        maxcnt = cnt[k];
                if(maxcnt <= occur)
                    ans++;
                cnt[s[j - i + 1] - '0']--;
                if(!cnt[s[j - i + 1] - '0'])
                    occur--;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}