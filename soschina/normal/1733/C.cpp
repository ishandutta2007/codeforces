#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
const int N = 1e5 + 1;
typedef pair<int, int> duo;

int t, n, a[N];
vector<duo> ans;

int main(){
    scanf("%d", &t);
    while(t--){
        ans.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if(n == 1){
            puts("0");
            continue;
        }
        ans.push_back(duo(1, n));
        if((a[1] + a[n]) & 1)
            a[n] = a[1];
        else
            a[1] = a[n];
        for (int i = 2; i < n; i++){
            if((a[1] + a[i]) & 1)
                ans.push_back(duo(1, i));
            else
                ans.push_back(duo(i, n));
        }
        printf("%d\n", (int)ans.size());
        for(duo pr : ans)
            printf("%d %d\n", pr.first, pr.second);
    }
    return 0;
}