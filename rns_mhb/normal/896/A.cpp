#include <bits/stdc++.h>
using namespace std;

char f0[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char a[] = "What are you doing while sending \"";
char b[] = "\"? Are you busy? Will you send \"";
char c[] = "\"?";

#define N 100005

typedef long long ll;
int n, q;
ll l[N];
ll k;

char calc(int n, ll k) {
    if (n <= 53 && l[n] < k) return '.';
    if (!n) return f0[k-1];
    if (n > 53) {
        if (k > 34) return calc(n - 1, k - 34);
        else return a[k-1];
    }
    if (k <= 34) return a[k-1];
    if (k <= 34 + l[n-1]) return calc(n - 1, k - 34);
    if (k <= 34 + l[n-1] + 32) return b[k-34-l[n-1]-1];
    if (k <= 34 + l[n-1] + 32 + l[n-1]) return calc(n - 1, k - 34 - l[n-1] - 32);
    return c[k-34-l[n-1]-32-l[n-1]-1];
}

int main() {
    l[0] = 75;
    for (int i = 1; i < N-2; i ++) l[i] = l[i-1] * 2ll + 68;
//    cout<<a[33]
//    for (int i = 1; i <= 100; i ++) cout<<i<<" "<<l[i]<<endl;
    scanf("%d", &q);
    while (q --) {
        scanf("%d %I64d\n", &n, &k);
        printf("%c", calc(n, k));
    }
//cout<<calc(27313, 5);
//    for (int i = 1; i <= 100; i ++) cout<<calc(1, i);
}