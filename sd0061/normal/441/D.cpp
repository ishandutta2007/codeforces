#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 3005;

int a[N] , n , K , f[N];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}
void work() {
    int i , j;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    scanf("%d",&K);
    vector< pair<int , int> > res;
    while (1) {
        for (i = 1 ; i <= n ; ++ i)
            f[i] = i;
        int cnt = n;
        for (i = 1 ; i <= n ; ++ i)
            if (getf(i) != getf(a[i]))
                -- cnt , f[getf(i)] = getf(a[i]);
        if (cnt + K == n)
            break;
        if (cnt + K < n) {
            vector<int> v[N];
            for (i = 1 ; i <= n ; ++ i) {
                v[getf(i)].push_back(i);
            }
            pair<int , int> p(1 << 30 , 1 << 30);
            for (i = 1 ; i <= n ; ++ i) {
                if (v[i].size() < 2)
                    continue;
                sort(v[i].begin() , v[i].end());
                p = min(p , make_pair(v[i][0] , v[i][1]));
            }
            res.push_back(p);
            swap(a[p.first] , a[p.second]);
        } else {
            for (i = 1 ; i <= n ; ++ i)
                for (j = i + 1 ; j <= n ; ++ j)
                    if (getf(i) != getf(j)) {
                        res.push_back(make_pair(i , j));
                        swap(a[i] , a[j]);
                        goto tt;
                    }           
        }
    tt:;
    }
    printf("%d\n" , (int)res.size());
    for (auto it : res)
        printf("%d %d\n" , it.first , it.second);
}

int main() {
    work();
    return 0;
}