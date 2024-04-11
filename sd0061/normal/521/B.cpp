#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 9;
int n;
LL power[N];
pair<int , int> a[N];
map< pair<int , int> , int > h;
vector<int> e[N];
int deg[N];

bool check(int x , int y) {
    for (int i = -1 ; i <= 1 ; ++ i) {
        if (!h.count(make_pair(x + i , y + 1)))
            continue;
        int j;
        for (j = -1 ; j <= 1 ; ++ j)
            if (i + j != 0 && h.count(make_pair(x + i + j , y)))
                break;
        if (j <= 1)
            continue;
        return 0;
    }
    return 1;
}

void work() {
    int i , j , x , y;
    scanf("%d",&n);
    power[0] = 1;
    for (i = 0 ; i < n ; ++ i) {
        power[i + 1] = power[i] * n % Q;
        scanf("%d%d",&x,&y);
        a[i] = make_pair(x , y);
        h[a[i]] = i;
    }
    set<int> S;
    for (i = 0 ; i < n ; ++ i) {
        x = a[i].first , y = a[i].second;
        if (check(x , y))
            S.insert(i);
    }
    int t = 0;
    LL res = 0;
    while (!S.empty()) {
        if (t & 1) {
            x = *S.begin();
        } else {
            x = *S.rbegin();
        }
        //cout << x << endl;
        S.erase(x) , ++ t;
        res += x * power[n - t] % Q;
        res %= Q;
        h.erase(a[x]);
        y = a[x].second , x = a[x].first;
        for (j = -2 ; j <= 2 ; ++ j)
            if (h.count(make_pair(x + j , y)))
                if (check(x + j , y))
                    S.insert(h[make_pair(x + j , y)]);
                else
                    S.erase(h[make_pair(x + j , y)]);
        for (j = -1 ; j <= 1 ; ++ j)
            if (h.count(make_pair(x + j , y - 1)))
                if (check(x + j , y - 1))
                    S.insert(h[make_pair(x + j , y - 1)]);
                else
                    S.erase(h[make_pair(x + j , y - 1)]);
        
    }
    cout << res << endl;
    
}

int main() {
    work();
    return 0;
}