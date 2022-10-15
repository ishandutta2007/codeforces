#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool prime[500005];
int minprime[500005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) prime[i] = true;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) continue;
        minprime[i] = i;
        for (int j = i * 2; j <= n; j += i) {
            prime[j] = false;
            if (!minprime[j]) minprime[j] = i;
        }
    }
    vector<int> ans;
    for (int i = 2; i <= n; i++) ans.push_back(i / minprime[i]);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    return 0;
}