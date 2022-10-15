#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[150005][2];

bool check(int val)
{
    for (int i = 1; i <= n; i++) {
        if (a[i][0] % val != 0 && a[i][1] % val != 0) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &(a[i][0]), &(a[i][1]));
    vector<int> factors;
    for (int i = 1; i * i <= a[1][0]; i++) {
        if (a[1][0] % i == 0) {
            factors.push_back(i);
            factors.push_back(a[1][0] / i);
        }
    }
    for (int i = 1; i * i <= a[1][1]; i++) {
        if (a[1][1] % i == 0) {
            factors.push_back(i);
            factors.push_back(a[1][1] / i);
        }
    }
    sort(factors.begin(), factors.end());
    vector<int> real_factors;
    for (int i = 0; i < factors.size(); i++) {
        //printf("%d ", factors[i]);
        bool found = false;
        if (factors[i] == 1) found = true;
        for (int j = 0; j < i; j++) {
            if (factors[i] % factors[j] == 0 && factors[j] != 1) found = true;
        }
        if (!found) real_factors.push_back(factors[i]);
    }
    for (int i = 0; i < real_factors.size(); i++) {
        if (check(real_factors[i])) {
            printf("%d", real_factors[i]); return 0;
        }
    }
    printf("-1"); return 0;
}