#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int up = 4000010;
bool h[up];

int main() {
    int a=1,b=1;
    while(a<=up) {
        h[a] = true;
        if (a + 1 <= up) h[a+1] = true;
        a = 2 * a + 1 + b;
        b ^= 1;
    }
    int N;
    scanf("%d",&N);
    printf("%d\n",h[N]);
}