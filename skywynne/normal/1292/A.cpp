// Skywynne
#include<bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, m, q, cnt, A[3][N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= q; i ++)
    {
        int a, b;
        cin >> a >> b;
        a --;
        if (A[a][b] && A[!a][b])
            cnt --;
        if (A[a][b] && A[!a][b + 1])
            cnt --;
        if (A[a][b] && A[!a][b - 1])
            cnt --;
        A[a][b] ^= 1;
        if (A[a][b] && A[!a][b])
            cnt ++;
        if (A[a][b] && A[!a][b + 1])
            cnt ++;
        if (A[a][b] && A[!a][b - 1])
            cnt ++;
        puts(cnt ? "No" : "Yes");
    }
    return 0;
}