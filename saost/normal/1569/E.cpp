#include <iostream>
#include <map>
#define getBIT(x, i) ((x>>i)&1)
using namespace std;
const int N = 200005, MOD = 998244353;
int n, k, A, h, Top[6][32], Rank[33];
long long Pow[6], num[6] = {1, 2, 3, 5, 9, 17};
map<int,int> Map, Map2;

long long power(long long x, int k) {
    long long ans = 1;
    while (k > 0) {
        if (k&1) (ans *= x) %= MOD;
        (x *= x) %= MOD;
        k /= 2;
    }
    return ans;
}

void Decryption(int n, int i) {
    int cnt = 0;
    for(int j=0; j<n; ++j) Top[k][j] = j + 1;
    for(int j=k-1; j>=0; --j) {
        for(int w=0; w<1<<j; ++w) {
            int x = getBIT(i, cnt);
            Top[j][w] = Top[j+1][w*2 + !x];
            Rank[Top[j+1][w*2 + x]] = j+1;
            ++cnt;
        }
    }
    Rank[Top[0][0]] = 0;
}

void BruteForce(int k, int add) {
    n = 1<<k;
    int xuli = 1<<(n-1);
    for(int i=0; i<xuli; ++i) {
        Decryption(n, i);
        if (add == 0) {
            long long sum = 0;
            for(int j=1; j<=n; ++j) (sum += j * Pow[Rank[j]]) %= MOD;
            if (sum == h) {
                for(int i=1; i<=n; ++i) cout << num[Rank[i]] << ' ';
                exit(0);
            }
        }
        else {
            long long sum = 0, sum2 = 0;
            for(int j=1; j<=n; ++j) {
                (sum += (j + n * (add==2)) * Pow[Rank[j] ? Rank[j] + 1 : 0]) %= MOD;
                (sum2 += (j + n * (add==2)) * Pow[Rank[j] + 1]) %= MOD;
            }
            if (add == 1) Map[sum] = Map2[sum2] = i;
            else {
                int z = (MOD + h - sum) % MOD, z2 = (MOD + h - sum2) % MOD;
                if (Map2.count(z)) {
                    Decryption(n, Map2[z]);
                    for(int j=1; j<=n; ++j) cout << num[Rank[j] + 1] << ' ';
                    Decryption(n, i);
                    for(int j=1; j<=n; ++j) cout << num[Rank[j] ? Rank[j] + 1 : 0] << ' ';
                    exit(0);
                }
                if (Map.count(z2)) {
                    Decryption(n, Map[z2]);
                    for(int j=1; j<=n; ++j) cout << num[Rank[j] ? Rank[j] + 1 : 0] << ' ';
                    Decryption(n, i);
                    for(int j=1; j<=n; ++j) cout << num[Rank[j] + 1] << ' ';
                    exit(0);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> k >> A >> h;
    for(int i=0; i<=5; ++i) Pow[i] = power(A, num[i]);
    if (k < 5) {
        BruteForce(k, 0);
        cout << -1;
    }
    else {
        k = 4;
        BruteForce(4, 1);
        BruteForce(4, 2);
        cout << -1;
    }
}