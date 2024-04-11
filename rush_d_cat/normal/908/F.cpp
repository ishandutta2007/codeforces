#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 300000+10;
#define min(x, y) ((x<y)?(x):(y))
#define max(x, y) ((x>y)?(x):(y))
int n, p[N]; char op[2]; 
vector<LL> v[4];
vector<LL> tmp;
LL res[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %s", &p[i], op + 1);
        if (op[1] == 'G') { 
            v[1].push_back(p[i]);
        }
        if (op[1] == 'B') {
            v[2].push_back(p[i]);
        }
        if (op[1] == 'R') {
            v[3].push_back(p[i]);
        }
    }
    if (v[1].size() == 0) {
        int ans = (v[2].size() ? v[2][v[2].size()-1]-v[2][0] : 0) + (v[3].size() ? v[3][v[3].size()-1]-v[3][0] : 0);
        printf("%d\n", ans); return 0;
    }

    LL ans = 0;
    for (int i = 0; i < v[1].size() - 1; i ++) 
    {
        int lb1 = lower_bound(v[2].begin(),v[2].end(),v[1][i]) - v[2].begin();
        int rb1 = lower_bound(v[2].begin(),v[2].end(),v[1][i+1]) - v[2].begin() - 1;
        int mx1 = 0;

        tmp.clear();
        tmp.push_back(v[1][i]);
        for (int j=lb1;j<=rb1;j++) {
            if (j<v[2].size() && v[1][i] <= v[2][j] && v[2][j] <= v[1][i+1])
                tmp.push_back(v[2][j]);
        }
        tmp.push_back(v[1][i+1]);
        for (int j=0;j<tmp.size()-1;j++) {
            mx1 = max(mx1, tmp[j+1]-tmp[j]);
        }


        int lb2 = lower_bound(v[3].begin(),v[3].end(),v[1][i]) - v[3].begin();
        int rb2 = lower_bound(v[3].begin(),v[3].end(),v[1][i+1]) - v[3].begin() - 1;
        int mx2 = 0;

        tmp.clear();
        tmp.push_back(v[1][i]);
        for (int j=lb2;j<=rb2;j++) {
            if (j<v[3].size() && v[1][i] <= v[3][j] && v[3][j] <= v[1][i+1])
                tmp.push_back(v[3][j]);
        }
        tmp.push_back(v[1][i+1]);
        for (int j=0;j<tmp.size()-1;j++) {
            mx2 = max(mx2, tmp[j+1]-tmp[j]);
        }

        res[i] = mx1 + mx2;
        ans += min(2*(v[1][i+1]-v[1][i]), 3*(v[1][i+1]-v[1][i]) - res[i]);
    }
    //printf("%lld\n", ans);

    if (v[2].size() > 0) {
        if (v[2][0] < v[1][0]) ans += v[1][0] - v[2][0];
        if (v[2][v[2].size()-1] > v[1][v[1].size()-1]) ans += v[2][v[2].size()-1] - v[1][v[1].size()-1];
    }
    if (v[3].size() > 0) {
        if (v[3][0] < v[1][0]) ans += v[1][0] - v[3][0];
        if (v[3][v[3].size()-1] > v[1][v[1].size()-1]) ans += v[3][v[3].size()-1] - v[1][v[1].size()-1];
    }
    printf("%lld\n", ans);
}

/*


G  R R R R R R  G   G   G


B R G R R


*/