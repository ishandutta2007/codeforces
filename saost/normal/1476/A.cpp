#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i=l; i<=r; i++)
#define REP(i, l, r) for(int i=l; i<r; i++)
#define FORD(i, r, l) for(int i=r; i>=l; i--)
#define REPD(i, r, l) for(int i=r-1; i>=l; i--)
using namespace std;
long long n, t, k;
void ReadInt(long long &x) {
    char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    long long deg = 1;
    if (c == '-') deg = -1, c = getchar();
    x = 0;
    while (isdigit(c)) x = (x<<3) + (x<<1) + c - '0', c = getchar();
    x *= deg;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        k = (n+k-1)/k*k;
        cout << (k-1+n)/n << '\n';
    }
}