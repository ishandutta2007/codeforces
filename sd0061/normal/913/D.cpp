#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , T;
int a[N] , t[N];
int o[N];

int main() {
    scanf("%d%d" , &n , &T);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d%d" , &a[i] , &t[i]);
        o[i] = i;
    }
    sort(o , o + n , [](int x , int y) {
            return make_pair(-a[x] , t[x]) < make_pair(-a[y] , t[y]);
        });
    int sum = 0;
    priority_queue< pair<int , int> > Q;

    for (int k = n , j = 0 ; k >= 0 ; -- k) {
        while (j < n && a[o[j]] >= k) {
            int x = o[j];
            sum += t[x];
            Q.push({t[x] , x});
            while (Q.size() > k) {
                sum -= Q.top().first;
                Q.pop();
            }
            ++ j;
        }
        //cout << k << ' ' << j <<  endl;

        while (Q.size() > k) {
            sum -= Q.top().first;
            Q.pop();
        }
        if (sum <= T && Q.size() == k) {
            printf("%d\n%d\n" , k , k);
            while (!Q.empty()) {
                printf("%d " , Q.top().second + 1);
                Q.pop();
            }
            puts("");
            break;
        }
    }
}