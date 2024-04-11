#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2005;

string d[] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
char s[10];
int n, a[sz][10];

bool vis[sz][sz];
int dp[sz][sz];

int fnc(int pos, int k)
{
    if(pos > n) {
        if(!k) return 0;
        return -1;
    }
    if(vis[pos][k]) return dp[pos][k];

    vis[pos][k] = 1;
    for(int i=9; i>=0; i--) {
        int x = a[pos][i];
        if(x >= 0 && x <= k) {
            int got = fnc(pos+1, k-x);
            if(got >= 0) return dp[pos][k] = i;
        }
    }
    return dp[pos][k] = -1;
}

int main()
{
    int k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        scanf("%s", s);
        for(int j=0; j<10; j++) {
            int cnt = 0;
            for(int k=0; k<7; k++) {
                if(s[k] != d[j][k]) {
                    if(s[k] == '1') {
                        cnt = -1;
                        break;
                    }
                    else cnt++;
                }
            }
            a[i][j] = cnt;
        }
    }

    if(fnc(1, k) < 0) puts("-1");
    else {
        for(int i=1; i<=n; i++) {
            int x = fnc(i, k);
            printf("%d", x);
            k -= a[i][x];
        }
    }
}