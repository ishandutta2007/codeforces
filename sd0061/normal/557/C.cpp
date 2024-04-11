#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;

int n;
pair<int , int> a[N];
multiset<int> Hash;
void work() {
    int sum = 0;
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i].first);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i].second);
        sum += a[i].second;
    }
    int res = 1 << 30;
    sort(a , a + n);
    for (int i = 0 ; i < n ; ) {
        int j = i;
        int delta = 0;        
        while (j < n && a[j].first == a[i].first) {
            delta += a[j].second;
            ++ j;
        }
        int k = j - i - 1;
        auto it = Hash.rbegin();
        while (k -- && it != Hash.rend()) {
            delta += *it;
            ++ it;
        }
        res = min(res , sum - delta);
        while (i < j) {
            Hash.insert(a[i].second);
            ++ i;
        }
    }
    printf("%d\n" , res);

}

int main() {
    work();
    return 0;
}