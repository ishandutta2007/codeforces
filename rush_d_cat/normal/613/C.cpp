#include <iostream>

using namespace std;

int n, a[30];

void no_solution() {
    printf("0\n");
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= a[i]; j ++) {
            printf("%c", 'a'+i-1);
        }
    }
    printf("\n");
}

void pal_solution(int cnt) {
    printf("%d\n", cnt);
    int odd_pos = -1;
    for(int i = 1; i <= n; i ++) {
        if((a[i] / cnt) % 2) odd_pos = i;
    }

    for(int t = 1; t <= cnt; t ++) {

        for(int i = 1; i <= n; i ++) {
            if(i == odd_pos) continue;
            for(int j = 1; j <= a[i]/cnt/2; j ++) {
                printf("%c", i+'a'-1);
            }
        }

        for(int i = 1; i <= a[odd_pos]/cnt; i ++) {
            printf("%c", odd_pos+'a'-1);
        }

        for(int i = n; i >= 1; i --) {
            if(i == odd_pos) continue;
            for(int j = 1; j <= a[i]/cnt/2; j ++) {
                printf("%c", i+'a'-1);
            }
        }

    }
}

void nor_solution(int cnt) {
    printf("%d\n", cnt);
    for(int t = 1; t <= cnt; t ++) {
        if(t % 2) {
            for(int i = 1; i <= n; i ++) {
                for(int j = 1; j <= a[i] / cnt; j ++) {
                    printf("%c", i+'a'-1);
                }
            }
        } else {
            for(int i = n; i >= 1; i --) {
                for(int j = 1; j <= a[i] / cnt; j ++) {
                    printf("%c", i+'a'-1);
                }
            }
        }
    }
}

bool chk(int x) 
{
    int ok = 1;

    int odd = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i] % x) return 0;
        if((a[i] / x) % 2) odd ++;
    }

    if(x % 2 == 0) {
        nor_solution(x);
        return 1;
    }

    if(odd == 1) {
        pal_solution(x);
        return 1;
    }

    return 0;
}

int main() 
{
    scanf("%d", &n);
    
    int mn = 1e6;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        mn = min(mn, a[i]);
    }

    for(int x = mn; x >= 1; x --) {
        if(chk(x)) return 0;
    }

    no_solution();


}