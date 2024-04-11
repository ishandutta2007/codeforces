#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N,a[100010],b[100010];

int main() {
    scanf("%d",&N);
    int odcnt = 0;
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    int tmpcnt = 0;
    int S = 0;
    for (int i=1;i<=N;i++) {
        b[i] = a[i] / 2;
        S += b[i];
    }
    for (int i=1;i<=N;i++) {
        if (S == 0) {
            break;
        }
        if ((a[i] + 10000) % 2 == 1) {
            if (a[i] < 0 && S > 0) {
                S--;
                b[i]--;
            } else if (a[i] > 0 && S < 0) {
                b[i]++;
                S++;
            }
        }
    }
    for (int i=1;i<=N;i++) {
        printf("%d\n",b[i]);
    }
}