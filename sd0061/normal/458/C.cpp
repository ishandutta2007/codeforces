#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
const int N = 100005;
typedef long long LL;
int n , m , K = 100000;

vector<int> tot[N];
pair<int , int> a[N];
int c[N] , s[N];
void add(int *C , int x , int w) {
    while (x <= 10000) {
        C[x] += w;
        x += x & -x;
    }
}
int query(int *C , int x) {
    int res = 0;
    while (x > 0) {
        res += C[x];
        x -= x & -x;
    }
    return res;
}
pair<int , int> getKth(int k) {
    int x = 0 , i;
    for (i = 13 ; i >= 0 ; -- i)
        if (x + (1 << i) <= 10000 && c[x + (1 << i)] < k) {
            x += 1 << i;
            k -= c[x];
        }
    return make_pair(x , k);
}


void work() {
    int i , j , k , x , y;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        if (y == 0)
            ++ m;
        else
            tot[x].push_back(y);
    }
    n = K , K = 0; int R = 0;
    for (i = 1 ; i <= n ; ++ i) {
        sort(tot[i].begin() , tot[i].end() , greater<int>());
        for (j = 0 ; j < tot[i].size() ; ++ j)
            a[K ++] = make_pair(j + 1 , tot[i][j]);
        R = max(R , (int)tot[i].size());
    }
    sort(a , a + K , greater< pair<int , int> >());
    for (i = 0 ; i < K ; ++ i) {
        add(c , a[i].second + 1 , 1);
        add(s , a[i].second + 1 , a[i].second);
    }
    int res = 1 << 30 , sum = 0;
    for (i = R + 1 , j = 0; i >= 0 ; -- i) {
        while (j < K && a[j].first > i) {
            add(c , a[j].second + 1 , -1);
            add(s , a[j].second + 1 , -a[j].second);
            sum += a[j].second;
            ++ m , ++ j;
        }
        if (m <= i) {
            k = i - m + 1;
            pair<int , int> w = getKth(k);
            int Cnt = query(s , w.first) + w.first * w.second;
            res = min(res , sum + Cnt);
        } else {
            res = min(res , sum);
        }
    }
    cout << res << endl;
}


int main() {
    work();
    return 0;
}