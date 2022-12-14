#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
#define M 202020
const int mod = 1000000007;
typedef pair<int, int> pii;
#define x first
#define y second

int n;
char s[M];
int flag[26][M];
int len[M];

int main() {
    //freopen("A2.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        len[i] = strlen(s);
        for (int j = 0; s[j]; j++) flag[s[j] - 'a'][i] = 1;
    }
    int answer = 0;
    for (int i = 0; i < 26; i++) for (int j = i + 1; j < 26; j++) {
        int tmp = 0;
        for (int k = 1; k <= n; k++) {
            bool res = 1;
            for (int r = 0; r < 26; r++) if (r != i && r != j && flag[r][k]) res = 0;
            if (res) tmp += len[k];
        }
        if (answer < tmp) answer = tmp;
    }
    printf("%d\n", answer);
    return 0;
}