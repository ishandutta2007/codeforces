#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef long long LL;
int n , m , K;

LL inf = 200000000005LL;

tuple<int , int , int> t[N];
multiset<LL> h[N];
LL mn[N];


int main() {
    scanf("%d%d%d" , &n , &m , &K);
    vector<int> d;
    for (int i = 0 ; i < m ; ++ i) {
        int x , y , z , c;
        scanf("%d%d%d%d" , &x , &y , &z , &c);
        if (z == 0) {
            t[i] = make_tuple(x , y , c);
        } else {
            h[z].insert(c);
            t[i] = make_tuple(x , -z , c);
        }
    }
    sort(t , t + m);

    LL res = 1LL << 60;
    LL Lsum = 0 , Rsum = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        mn[i] = inf;
        Lsum += mn[i];
        h[i].insert(inf);
        Rsum += *h[i].begin();
    }
    //cout << Rsum << endl;
    int i = 0 , j = 0;
    for (int T = 0 ; T <= 1000000 ; ++ T) {
        while (i < m && get<0>(t[i]) < T) {
            int x = get<1>(t[i]);
            if (x > 0) {
                Lsum -= mn[x];
                mn[x] = min(mn[x] , (LL)get<2>(t[i]));
                Lsum += mn[x];
            }
            ++ i;
        }
        while (j < m && get<0>(t[j]) < T + K) {
            int x = -get<1>(t[j]);
            if (x > 0) {
                Rsum -= *h[x].begin();
                h[x].erase(h[x].find(get<2>(t[j])));
                Rsum += *h[x].begin();
            }
            ++ j;
        }
        /*if (T <= 10) {
            cout << T << ' ' <<  Lsum << ' ' << Rsum << endl;
            }*/
        res = min(res , Lsum + Rsum);
    }
    if (res >= inf) {
        puts("-1");
    } else {
        cout << res << endl;
    }

}