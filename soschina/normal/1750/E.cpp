// LUOGU_RID: 93144408
#include <cstdio>
#include <algorithm>
#define lowbit(i) (i&-i)
using namespace std;
const int N = 2e5 + 2, L = 20;
//(ri - le - |sum|) / 2 + |sum|

int lg2[N] = {-1}, t, n, sum[N], st[N][L], pos[N][L];
char s[N];
long long ans;

int getpos(int l, int r){
    int b = lg2[r - l + 1];
    return st[l][b] < st[r - (1 << b) + 1][b] ? pos[l][b] : pos[r - (1 << b) + 1][b];
}

void solve(int l, int r){
    if(l > r)
        return;
    int mid = getpos(l, r);
    ans -= 1ll * sum[mid] * (mid - l + 1) * (r - mid + 1);
    solve(l, mid - 1);
    solve(mid + 1, r);
}

int main(){
    for (int i = 1; i < N; i++)
        lg2[i] = lg2[i - 1] + (i == (i & -i));
    scanf("%d", &t);
    while(t--){
        ans = 0;
        scanf("%d%s", &n, s + 1);
        sum[0] = 0;
        for (int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
            st[i][0] = sum[i];
            pos[i][0] = i;
        }
        for (int j = 1; j < L; j++)
            for (int i = 0; i + (1 << j) - 1 <= n; i++){
                if(st[i][j - 1] < st[i + (1 << (j - 1))][j - 1]){
                    st[i][j] = st[i][j - 1];
                    pos[i][j] = pos[i][j - 1];
                }
                else{
                    st[i][j] = st[i + (1 << (j - 1))][j - 1];
                    pos[i][j] = pos[i + (1 << (j - 1))][j - 1];
                }
            }
        solve(0, n);
        sort(sum, sum + 1 + n);
        for (int i = 0; i <= n; i++)
            ans += 1ll * (i + 1) * sum[i];
        printf("%lld\n", ans);
    }
	return 0;
}