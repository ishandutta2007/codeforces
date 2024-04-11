#include <iostream>
#include <string>
using namespace std;

int c[502][502];
int d[502][502];
string s[502];
int r1[300005], c1[300005], r2[300005], c2[300005];
int ans[300005];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < q; i++){
        scanf("%d %d %d %d", &r1[i], &c1[i], &r2[i], &c2[i]);
        r1[i]--; c1[i]--; r2[i]--; c2[i]--;
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            if(s[i][j] == 'R' && s[i][j + 1] == 'G' && s[i + 1][j] == 'Y' && s[i + 1][j + 1] == 'B'){
                int l = min(min(i + 1, j + 1), min(n - 1 - i, m - 1 - j));
                bool f = true;
                for(int k = 0; k < l; k++){
                    for(int x = 0; x <= k; x++){
                        if(s[i - x][j - k] != 'R' || s[i - x][j + 1 + k] != 'G' ||
                           s[i + 1 + x][j - k] != 'Y' || s[i + 1 + x][j + 1 + k] != 'B'){
                            d[i][j] = k;
                            f = false;
                            break;
                        }
                    }
                    for(int y = 0; y < k; y++){
                        if(s[i - k][j - y] != 'R' || s[i - k][j + 1 + y] != 'G' ||
                           s[i + 1 + k][j - y] != 'Y' || s[i + 1 + k][j + 1 + y] != 'B'){
                            d[i][j] = k;
                            f = false;
                            break;
                        }
                    }
                    if(!f) break;
                }
                if(f) d[i][j] = l;
            }
        }
    }
    for(int k = 1; k <= min(n, m) / 2; k++){
        for(int i = n - k - 1; i >= k - 1; i--){
            for(int j = m - k - 1; j >= k - 1; j--) if(d[i][j] >= k) c[i][j] = 1;
        }
        for(int i = n - k - 1; i >= k - 1; i--){
            for(int j = m - k - 1; j >= k - 1; j--) c[i][j] += c[i][j + 1];
        }
        for(int i = n - k - 1; i >= k - 1; i--){
            for(int j = m - k - 1; j >= k - 1; j--) c[i][j] += c[i + 1][j];
        }
        for(int i = 0; i < q; i++){
            if(r1[i] >= r2[i] || c1[i] >= c2[i] || ans[i] < k - 1) continue;
            if(c[r1[i]][c1[i]] - c[r2[i]][c1[i]] - c[r1[i]][c2[i]] + c[r2[i]][c2[i]] > 0) ans[i] = k;
            r1[i]++; c1[i]++; r2[i]--; c2[i]--;
        }
        for(int i = k - 1; i < n - k; i++) for(int j = k - 1; j < m - k; j++) c[i][j] = 0;
    }
    for(int i = 0; i < q; i++) printf("%d\n", ans[i] * ans[i] * 4);
}