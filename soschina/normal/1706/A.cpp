#include <cstdio>
using namespace std;
const int N = 52;

int t, n, m, a[N];
char s[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
            s[i] = 'B';
        s[m + 1] = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] > m + 1 - a[i])
                a[i] = m + 1 - a[i];
            if(s[a[i]] == 'B')
                s[a[i]] = 'A';
            else
                s[m + 1 - a[i]] = 'A';
        }
        printf("%s\n", s + 1);
    }
    return 0;
}