#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
const int N = 1e5 + 1;

int t, n, m, a[N];
vector<int> vec;

int main(){
    scanf("%d", &t);
    while(t--){
        vec.clear();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + m);
        for (int i = 2; i <= m; i++)
            vec.push_back(a[i] - a[i - 1] - 1);
        vec.push_back(n - a[m] + a[1] - 1);
        sort(vec.begin(), vec.end(), greater<int>());
        while(vec.size() && vec.back() == 0)
            vec.pop_back();
        long long ans = 0, sum = 0;
        for (int i = 0; i < vec.size(); i++){
            long long day = 2 * i + 1;
            sum += vec[i];
            ans = max(ans, sum - (1ll + day) * day / 2 + (vec[i] == 2 * day - 1));
        }
        printf("%lld\n", n - ans);
    }
	return 0;
}