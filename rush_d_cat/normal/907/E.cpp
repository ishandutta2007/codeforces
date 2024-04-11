#include <iostream>
#include <vector>
using namespace std;
vector<int> g[22];
int n, m, u, v;
int s[22];

int is_connect[1<<22];
void init() {
    is_connect[0] = 1;
    for (int S = 0; S < (1 << n); S ++) {
        if (!is_connect[S]) continue;
        //printf("connect %d\n", S);
        for (int i = 0; i < n; i ++) 
            if ( (((S>>i)&1) == 0) && ( ((s[i] & S) != 0) || S == 0) )
                is_connect[S|(1<<i)] = 1; 
    }
}

bool is_core(int bit) {
    /*
    1. connect
    2. orsum = (1 << n)
    */

    if (!is_connect[bit]) 
        return false;
    
    int orsum = 0;
    for (int i = 0; i < n; i ++) {
        if ((bit >> i) & 1)
            orsum |= s[i];
    }
    if (orsum != (1<<n)-1) 
        return false;

    return true;

}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        u --, v --;
        s[u] |= (1 << v); s[u] |= (1 << u); 
        s[v] |= (1 << u); s[v] |= (1 << v);
    }
    if (m == n * (n - 1) / 2) {
        return 0*printf("0\n");
    }
    init();

    int best = -1, cnt_not_leaf = 22; 
    for (int bit = 0; bit < (1 << n); bit ++) {
        if (is_core(bit)) {
            int tmp = 0;
            for (int i = 0; i < n; i ++) 
                if ((bit >> i) & 1) 
                    tmp ++;
        
            if (tmp < cnt_not_leaf) {
                cnt_not_leaf = tmp;
                best = bit;
            }
        } 
    }

    printf("%d\n", cnt_not_leaf);
    for (int i = 0; i < n; i ++)
        if ((best >> i) & 1)
            printf("%d ", i+1);

    printf("\n");
}