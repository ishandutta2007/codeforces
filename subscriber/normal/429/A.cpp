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
#include<cstring>
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
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int n, A[N], B[N];
vector<int> v[N];
vector<int> ans;

void rec(int x, int o0, int o1, int p) {
    if (o0 ^ A[x] != B[x]) {
        ans.pb(x);
        o0 ^= 1;
    }
    for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) {
        rec(v[x][i], o1, o0, x);
    }
}

int main(){
//    freopen("1.in","r",stdin);  
 //   freopen("1.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        v[x].pb(y);
        v[y].pb(x);
    }
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < n; i++) scanf("%d", &B[i]);
    rec(0, 0, 0, -1);
    cout << ans.size() << endl;
    if (ans.size()) {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i] + 1);
    }
    return 0;
}