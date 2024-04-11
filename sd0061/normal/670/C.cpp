#include <bits/stdc++.h>
using namespace std;
map<int, int> cnt;
int n , m;
int a[200005] , b[200005];
int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        cnt[x] ++;
    }
    scanf("%d" , &m);
    for (int i = 1 ; i <= m ; ++ i) {
        scanf("%d" , &a[i]);
    }
    int res = 0;
    pair<int , int> val(-1 , -1);
    for (int i = 1 ; i <= m ; ++ i) {
        scanf("%d" , &b[i]);
        pair<int , int> w;
        if (cnt.count(a[i]))
            w.first = cnt[a[i]];
        if (cnt.count(b[i]))
            w.second = cnt[b[i]];
        if (w > val) {
            val = w;
            res = i;
        }
    }
    cout << res << endl;
}