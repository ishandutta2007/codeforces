#include <cstdio>
using namespace std;
const int N = 501;

int t, n, k, r, c;
bool ans[N][N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d", &n, &k, &r, &c);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = 0;
        r--, c--;
        for (int i = r; i >= 0; i--){
            int j = ((c - (r - i)) % n + n) % n;
            do{
                ans[i][j] = 1;
                j = (j + k) % n;
            } while (j != ((c - (r - i)) % n + n) % n);
        }
        for (int i = r; i < n; i++){
            int j = (c + (i - r)) % n;
            do{
                ans[i][j] = 1;
                j = (j + k) % n;
            } while (j != (c + (i - r)) % n);
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                putchar(ans[i][j] ? 'X' : '.');
            putchar('\n');
        }
    }
    return 0;
}