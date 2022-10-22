#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const int M = 200005;

int n , b[N];
pair<int , int> a[N];
int f[N];
bool cmp(pair<int , int> A , pair<int , int> B) {
    return A.first + A.second < B.first + B.second;
}

void work () {
    int i , j;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&a[i].first , &a[i].second);
        //a[i].first = rand() % 100000;
            //        a[i].second = rand() % 10000;        
    }
    sort(a , a + n , cmp);
    for (i = 0 ; i < n ; ++ i) {
        b[i] = a[i].first + a[i].second;
    }
    for (i = 0 ; i < n ; ++ i) {
        f[i + 1] = f[i];
        j = upper_bound(b , b + n , a[i].first - a[i].second) - b;
        f[i + 1] = max(f[i + 1] , f[j] + 1);
    }
    cout << f[n] << endl;
        
    
}

int main () {
    work();
    return 0;
}