#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 200005;


int n , K;
int a[N];
LL b[N];
int main() {
    scanf("%d%d" , &n , &K);
    LL sum = 0;
    int R = -1;
    for (int i = 0 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    for (int i = 0 ; i <= n ; ++ i) {
        sum += a[i];
        R = i;
        if (sum % 2 != 0) {
            break;
        }
        sum /= 2;

    }
    //printf("%d\n" , R);

    for (int i = 0 ; i < n ; ++ i) {
        b[i] += a[i];
        if (b[i] < 0) {
            b[i + 1] += b[i];
            b[i] = -b[i];
        }
        b[i + 1] += b[i] / 2;
        b[i] %= 2;
    } b[n] += a[n];
    sum = 0; int res = 0;
    bool large = 0;
    for (int i = n ; i >= 0 ; -- i) {
        sum += b[i];
        if (abs(sum) > 1LL << 53)
            large = 1;
        if (i <= R && !large) {
//            printf("%d %lld\n" , i, sum);
            if (abs(a[i] - sum) <= K) {
                if (i != n || a[i] - sum !=0 )
                    ++ res;
                //  cout << "!" << i << endl;
            }
        }
        sum *= 2;
    }
    cout << res << endl;
    return 0;
}