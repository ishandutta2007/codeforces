#include <cstdio>

using namespace std;

const int MAXN = 1001000;
char ar[MAXN];

int main() {
    scanf("%s", ar);
    int cnt = 0;
    int sc = 0; 
    for(int i = 0; ar[i]; ++i) {
        if (ar[i] == '(') {
            sc++;
            cnt++;
        } else {
            if (sc > 0) {
                sc--;
                cnt++;
            }
        }
    }
    cnt -= sc;
    printf("%d\n", cnt);
    return 0;
}