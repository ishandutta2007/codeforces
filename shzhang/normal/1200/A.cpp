#include <cstdio>

using namespace std;

int n;
bool inuse[15];
char ops[100005];

int main()
{
    scanf("%d", &n);
    scanf("%s", ops);
    for (int i = 0; i < n; i++) {
        if (ops[i] == 'L') {
            for (int j = 0; j < 10; j++) {
                if (!inuse[j]) {inuse[j] = true; break;}
            }
        } else if (ops[i] == 'R') {
            for (int j = 9; j >= 0; j--) {
                if (!inuse[j]) {inuse[j] = true; break;}
            }
        } else {
            inuse[ops[i] - '0'] = false;
        }
    }
    for (int i = 0; i < 10; i++) printf("%d", inuse[i] ? 1 : 0);
    return 0;
}