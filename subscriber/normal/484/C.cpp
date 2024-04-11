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

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int k, d, n;

char s[1000111], ss[1000111];
int p[1000111];
int next[23][1000111];

int get(int x, int o) {
    if (o == 0) return x;
    if (o == 1) return p[x];

    int g = o - 1;
    int cur = x;

    for (int i = 20; i >= 0; i--) if (g & pw(i)) {
        cur = next[i][cur];
    }

    if (cur >= k) return cur;
    return p[cur];
}

int main(){
//    freopen(TASK".in","r",stdin);   
//    freopen(TASK".out","w",stdout);
    gets(s);
    n = strlen(s);
    int t;
    cin >> t;
    while (t--) {
        scanf("%d%d", &k, &d);
        vector<pair<int, int> > q;
        for (int i = 0; i < k; i++) q.pb(mp(i % d, i));
        sort(q.begin(), q.end());

        for (int i = 0; i < k; i++) p[i] = q[i].S;

        for (int i = 0; i < k; i++) next[0][i] = p[i] + 1;

        for (int i = k; i <= n; i++) next[0][i] = i + 1;

        for (int i = 1; i < 22; i++) for (int j = 0; j <= n; j++) next[i][j] = next[i - 1][next[i - 1][j]];

        for (int i = 0; i <= n - k; i++) {
            int x = get(0, i + 1);
            ss[i] = s[x];
        }
        for (int i = n - k + 1; i < n; i++) {
            int x = get(i - (n - k), (n - k + 1));
            ss[i] = s[x];
        }
        for (int i = 0; i < n; i++) s[i] = ss[i];
        puts(s);
    }
    return 0;
}