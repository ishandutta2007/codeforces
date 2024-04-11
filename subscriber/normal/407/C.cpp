#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n, m;
int a[111111];
int C[111111][107];
int f[107][111111];
int x, y, k;

int main(){
//  freopen("1.in","r",stdin);  
//  freopen("1.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= n + 100; i++) for (int j = 0; j <= 100; j++)
    if (j == 0 || j == i) C[i][j] = 1; else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    for (int z = 0; z < m; z++) {
        scanf("%d%d%d", &x, &y, &k);
        x--;
        f[k][x] = (f[k][x] + 1) % M;
        for (int i = k; i >= 0; i--) {
            int t = C[y - x + k - i][k - i];
            if (i < k) t = (t - C[y - x + k - i - 1][k - i - 1] + M) % M;
//          cout << t << " " << C[y - x + k - i][k - i] << " " << C[y - x + k - i - 1][k - i - 1] << endl;
            f[i][y] = (f[i][y] - t + M) % M;
        }
        }
/*        for (int i = 0; i < 7; i++) {
        for (int j = 0; j < n; j++ )cout << f[i][j] << " ";
            cout << endl;
        }*/
        for (int i = 100; i >= 0; i--) for (int j = 0; j < n; j++) {
            if (i < 100) f[i][j] = (f[i][j] + f[i + 1][j]) % M;
            if (j > 0) f[i][j] = (f[i][j] + f[i][j - 1]) % M;
        }
        for (int i = 0; i < n; i++) a[i] = (a[i] + f[0][i]) % M;
        for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
        cout << a[n - 1] << endl;
    return 0;
}