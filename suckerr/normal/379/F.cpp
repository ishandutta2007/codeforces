#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1111111;

vector<int> e[N];

int result[N];
int n = 4, q, s, t, ans;

int father[N][21];

int dep[N];
int who;

int calcDist(int a, int b) {
    int res = 0;
    if (dep[a] < dep[b])
        swap(a, b);
    for(int i = 20; i >= 0; i--) {
        if (dep[a] - (1 << i) >= dep[b]) {
            a = father[a][i];
            res += (1 << i);
        }
    }
    
    if (a == b)
        return res;
        
    for(int i = 20; i >= 0; i--) {
        if (father[a][i] != father[b][i]) {
            res += 2 * (1 << i);
            a = father[a][i];
            b = father[b][i];
        }
    }
    
    return res + 2;
}

int add(int a, int b) {
    father[b][0] = a;
    dep[b] = dep[a] + 1;
    for(int i = 1; i <= 20; i++) {
        father[b][i] = father[father[b][i - 1]][i - 1];
    }
    
    int tmp1 = calcDist(s, b), tmp2 = calcDist(b, t);
    if (tmp1 >= tmp2 && tmp1 > ans) {
        ans = tmp1;
        s = s;
        t = b;
    } else if (tmp2 > tmp1 && tmp2 > ans) {
        ans = tmp2;
        s = b;
        t = t;
    }
}

int main() {
    ans = 0;
    s = t = who = 1;
    
    add(1, 2);
    add(1, 3);
    add(1, 4);
    n = 4;
    
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        int v;
        scanf("%d", &v);
        add(v, ++n);
        add(v, ++n);
        
        printf("%d\n", ans);
    }   
    return 0;
}