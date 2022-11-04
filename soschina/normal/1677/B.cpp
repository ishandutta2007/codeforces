#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
const int N = 1e6 + 1;

int t, n, m, ans, a[N];
deque<bool> dq;
char s[N];

int main(){
    scanf("%d", &t);
    while(t--){
        ans = 0;
        dq.clear();
        scanf("%d%d%s", &n, &m, s);
        memset(a, 0, sizeof(int) * m);
        for (int i = 0; i < m; i++)
            dq.push_back(0);
        int last = m - 2;
        for (int i = 0; i < n * m; i++){
            bool now = dq.front();
            dq.pop_front();
            if(s[i] == '1' && !now){
                ans++;
                now = true;
            }
            dq.push_back(now);
            if(s[i] == '1'){
                if(last != -1){
                    if(last >= m - 1){
                        a[i % m]++;
                    }
                    last = -1;
                }
            }else{
                last++;
                if(last == m - 1){
                    a[i % m]--;
                }
            }
            ans += a[i % m];
            printf("%d ", ans + i / m + 1);
        }
        putchar('\n');
    }
    return 0;
}