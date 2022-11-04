#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 502;

int n, m, l[N], id[N];
char s[N];

bool cmp(int a, int b){
    return l[a] > l[b];
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        s[i] = '1';
        id[i] = i;
        printf("? ");
        for (int j = 1; j <= m; j++){
            if(j == i)
                putchar('1');
            else
                putchar('0');
        }
        putchar('\n');
        fflush(stdout);
        scanf("%d", &l[i]);
    }
    sort(id + 1, id + 1 + m, cmp);
    int last;
    printf("? %s\n", s + 1);
    fflush(stdout);
    scanf("%d", &last);
    for (int i = 1; i < m; i++){
        s[id[i]] = '0';
        printf("? %s\n", s + 1);
        fflush(stdout);
        int now;
        scanf("%d", &now);
        if(last - now == l[id[i]])
            s[id[i]] = '1';
        else
            last = now;
    }
    printf("! %d\n", last);
    return 0;
}