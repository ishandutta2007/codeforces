#include <bits/stdc++.h>
using namespace std;

typedef pair<double, int> P;
const int N = (int)1e5 + 500, M = (int)2e6 + 500;

int n,x,y,mod,m,a;
//int type[N];
P ti[M];

int gcd(int x, int y){
    return x == 0 ? y : gcd(y % x, x);
}

int main(){
    cin >> n >> x >> y;
    int g = gcd(x, y);
    x /= g, y /= g;
    mod = x + y;

    m = 0;
    for(int i = 1; i <= x; i++){
        ti[m].first = (double)i / x;
        ti[m++].second = (i != x ? 0 : 2);
    }
    for(int i = 1; i <= y; i++){
        ti[m].first = (double)i / y;
        ti[m++].second = (i != y ? 1 : 2);
    }
    assert(mod == m);
    sort(ti, ti+m);

//    for(int i = 0; i < m; i++) cout << ti[i].second << " ";

    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        a = (a + mod - 1) % mod;
        int type = ti[a].second;
        if(type == 0) printf("Vanya\n");
        else if(type == 1) printf("Vova\n");
        else printf("Both\n");
    }
}