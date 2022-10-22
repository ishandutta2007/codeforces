#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n , K , a[N];
int res[N];
pair<int , int> b[N];

int main() {
    scanf("%d%d" , &n , &K);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    priority_queue< pair<int , int> > Q;
    for (int i = 1 ; i <= K ; ++ i) {
        Q.push({a[i] , i});
    }
    long long sum = 0;
    for (int i = K + 1 ; i <= K + n ; ++ i) {
        if (i <= n) {
            Q.push({a[i] , i});
        }
        //cout << Q.top().first << endl;
        sum += (long long)Q.top().first * (i - Q.top().second);
        res[Q.top().second] = i;
        Q.pop();
    }
    cout << sum << endl;
    for (int i = 1 ; i <= n ; ++ i) {
        printf("%d%c" , res[i] , " \n"[i == n]);
    }
}