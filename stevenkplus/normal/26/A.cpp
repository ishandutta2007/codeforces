#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 3100;
bool ar[MAXN];
vector<int> primes;
void sieve(int N) {
    ar[0] = ar[1] = true;
    for(int i = 2; i < N; ++i) {
        if (!ar[i]) {
            primes.push_back(i);
            for(int j = i; j <= (N - 1) / i; ++j) {
                ar[i * j] = true;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    sieve(N);
    int cnt = 0;
    for(int i = 0; i < int(primes.size()); ++i) {
        for(int j = i + 1; j < int(primes.size()); ++j) {
            int pr = primes[i];
            while (pr <= N) {
                int k = pr * primes[j];
                while (k <= N) {
                    cnt++;
                    k *= primes[j];
                }
                pr *= primes[i];
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}