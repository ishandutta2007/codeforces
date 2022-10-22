#include <bits/stdc++.h>
using namespace std;
const int N = 50005;

int a[N];

int main() {
    int n , start , x;
    scanf("%d%d%d" , &n , &start , &x);
    for (int i = 0 ; i < n ; ++ i) {
        a[i] = i + 1;
    }
    srand(time(0));
    random_shuffle(a , a + n);
    vector< pair<int , int> > v;
    int res = 1 << 30;
    for (int i = 0 ; i < min(n , 1600) ; ++ i) {
        printf("? %d\n" , a[i]);
        fflush(stdout);
        int val , nxt;
        scanf("%d%d" , &val , &nxt);
        if (val >= x) {
            res = min(res , val);
        }
        v.emplace_back(val , nxt);
    }
    v.emplace_back(-1 << 30 , start);
    sort(v.begin() , v.end());

    auto it = lower_bound(v.begin() , v.end() , make_pair(x , 1 << 30))
        - v.begin() - 1;
    int w = v[it].first , y = v[it].second;
    while (w < x && y != -1) {
        printf("? %d\n" , y);
        fflush(stdout);
        int val , nxt;
        scanf("%d%d" , &w , &y);
        if (w >= x) {
            res = min(res , w);
        }
    }
    if (res == 1 << 30) {
        res = -1;
    }
    printf("! %d\n" , res);
    fflush(stdout);

    return 0;
}