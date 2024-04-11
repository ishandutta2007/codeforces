#include <cstdio>
#include <vector>

using namespace std;

#define MOD 998244353
#define mul(a, b) (((long long)(a) * (long long)(b)) % MOD)

int n, k;

int work(vector<int>& seq)
{
    int a, b;
    int prev = 0;
    if (seq[0] == -1) {
        a = 1; b = 1;
    } else {
        a = 0; b = 1; prev = seq[0];
    }
    for (int i = 1; i < seq.size(); i++) {
        if (seq[i] == -1) {
            int olda = a;
            a = mul(k-2, a) + b;
            if (a >= MOD) a -= MOD;
            b = mul(k-1, olda);
        } else {
            if (seq[i] != prev) {
                b = mul(k-2, a) + b;
                if (b >= MOD) b -= MOD;
            } else {
                b = mul(k-1, a);
            }
            a = 0;
            prev = seq[i];
        }
        //printf("%d: %d %d\n", i, a, b);
    }
    return (mul(k-1, a) + b) % MOD;
}

int main()
{
    scanf("%d%d", &n, &k);
    vector<int> seq1, seq2;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        if (i % 2) {
            seq2.push_back(a);
        } else {
            seq1.push_back(a);
        }
    }
    //printf("%d\n", work(seq1));
    //printf("%d\n", work(seq2));
    printf("%d", (int)mul(work(seq1), work(seq2)));
    return 0;
}