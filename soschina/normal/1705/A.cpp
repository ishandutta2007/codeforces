#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 201;

int t, n, k, a[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        for (int i = 0; i < 2 * n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n * 2);
        bool flag = true;
        for (int i = 0; i < n; i++)
            if(a[i] + k > a[i + n])
                flag = false;
        puts(flag ? "YES" : "NO");
    }
	return 0;
}