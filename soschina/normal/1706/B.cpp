#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 1;

int t, n, c;
vector<int> vec[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            vec[i].clear();
        for (int i = 1; i <= n; i++){
            scanf("%d", &c);
            vec[c].push_back(i);
        }
        for (int i = 1; i <= n; i++){
            int ans = vec[i].size() > 0;
            for (int j = 1; j < vec[i].size(); j++)
                if((vec[i][j] - vec[i][j - 1]) % 2 == 1)
                    ans++;
            printf("%d ", ans);
        }
        putchar('\n');
    }
    return 0;
}