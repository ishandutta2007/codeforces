#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , m;
pair<int , int> a[N];
pair<int , int> L[N] , R[N] , q[N];
int c[N] , o[N];
LL res[N];


int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i - 1].second);
        a[i - 1].first = i;
    }
    for (int i = 0 ; i < m ; ++ i) {
        scanf("%d%d" , &L[i].first , &L[i].second);
        scanf("%d%d" , &R[i].first , &R[i].second);
        res[i] = (LL)n * (n - 1) / 2;
    }

    for (int d = 0 ; d < 4 ; ++ d) {

        sort(a , a + n);
        for (int i = 0 ; i < m ; ++ i) {
            q[i].first = min(L[i].first , R[i].first);
            q[i].second = min(L[i].second , R[i].second);
            o[i] = i;
        }

        sort(o , o + m , [](int x , int y) {return q[x] < q[y];});
        memset(c , 0 , sizeof(c));
        for (int i = 0 , j = 0 ; i < m ; ++ i) {
            int x = q[o[i]].first , y = q[o[i]].second;
            while (j < n && a[j].first < x) {
                //cout << j << ' ' << a[j].first << ' ' << a[j].second << endl;
                for (int k = a[j].second ; k <= n ; k += k & -k) {
                    ++ c[k];
                }
                ++ j;
            }
            int sum = 0;
            for (int k = y - 1 ; k > 0 ; k -= k & -k) {
                sum += c[k];
            }
            res[o[i]] += (LL)sum * (sum - 1) / 2;
            res[o[i]] -= (LL)j * (j - 1) / 2;
        }

        for (int i = 0 ; i < n ; ++ i) {
            swap(a[i].first , a[i].second);
            a[i].first = n - a[i].first + 1;
        }
        for (int i = 0 ; i < m ; ++ i) {
            swap(L[i].first , L[i].second);
            L[i].first = n - L[i].first + 1;
            swap(R[i].first , R[i].second);
            R[i].first = n - R[i].first + 1;
        }
    }
    for (int i = 0 ; i < m ; ++ i) {
        printf("%lld\n" , res[i]);
    }
}