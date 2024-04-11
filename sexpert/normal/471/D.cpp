#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int pi[2*MAXN];
int A[2*MAXN], B[MAXN];

void prefix() {
    pi[0] = 0;
    for(int i = 1; i < 2*MAXN; i++) {
        int j = pi[i - 1];
        while(j > 0 && A[j] != A[i])
            j = pi[j - 1];
        if(A[i] == A[j]) j++;
        pi[i] = j;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    for(int i = 0; i < n; i++)
        cin >> B[i];
    int last;
    cin >> last;
    for(int i = 0; i < w - 1; i++) {
        int x;
        cin >> x;
        A[i] = x - last;
        last = x;
    }
    A[w - 1] = INT_MIN;
    if(w == 1) {
        cout << n << endl;
        return 0;
    }
    for(int i = 0; i < n - 1; i++)
        A[w + i] = B[i + 1] - B[i];
    //for(int i = 0; i < w + n - 1; i++)
    //    cout << A[i] << " ";
    cout << endl;
    prefix();
    int ans = 0;
    for(int i = 0; i < w + n - 1; i++)
        if(pi[i] == w - 1) ans++;
    cout << ans << endl;
}