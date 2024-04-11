#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;
typedef pair<int, int> duo;

int t, n, c, l, r;

vector<duo> vec[2];

int main(){
    scanf("%d", &t);
    while(t--){
        vec[0].clear();
        vec[1].clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d%d%d", &c, &l, &r);
            vec[c].push_back(duo(l, r));
        }
        sort(vec[0].begin(), vec[0].end());
        sort(vec[1].begin(), vec[1].end());
        int p[2] = {-1, -1};
        int i = 0, j = 0;
        int ans = 0;
        while(i < vec[0].size() || j < vec[1].size()){
            if(j == vec[1].size() || (i != vec[0].size() && vec[0][i].first < vec[1][j].first)){
                int newp = (int)(upper_bound(vec[1].begin(), vec[1].end(), duo(vec[0][i].second, 0x7fffffff)) - vec[1].begin()) - 1;
                p[1] = max(p[1], newp);
                if(p[0] < i && newp < j || p[0] == i && p[1] < j)
                    ans++;
                i++;
            }
            else{
                int newp = (int)(upper_bound(vec[0].begin(), vec[0].end(), duo(vec[1][j].second, 0x7fffffff)) - vec[0].begin()) - 1;
                p[0] = max(p[0], newp);
                if(p[1] < j && newp < i || p[1] == j && p[0] < i)
                    ans++;
                j++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}