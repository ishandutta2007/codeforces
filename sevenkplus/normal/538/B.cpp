#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int a[10], L; int n, S;

int main () {
    cin >> n;
    while (n) {
        a[L++] = n%10;
        n /= 10;
    }
    for (int i = 0; i < L; i ++) S = max(S, a[i]);
    printf ("%d\n", S);
    for (int i = 0; i < S; i ++) {
        int t = 0;
        for (int j = L-1; j >= 0; j --) {
            t *= 10;
            if (a[j] > i) t ++;
        }
        printf ("%d%c", t, i == S-1?'\n': ' ');
    }
    return 0; 
}