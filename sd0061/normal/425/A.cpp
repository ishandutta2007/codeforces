#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 2005
int n , K;
int a[N];

void work() {
    int i , j , k;
    scanf("%d%d",&n,&K);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    int ans = -1 << 30;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = i ; j <= n ; ++ j) {
            vector<int> A , B;
            int sum = 0;
            for (k = i ; k <= j ; ++ k) A.push_back(a[k]) , sum += a[k];
            for (k = 1 ; k < i ; ++ k) B.push_back(a[k]);
            for (k = j + 1 ; k <= n ; ++ k) B.push_back(a[k]);
            sort(A.begin() , A.end());
            sort(B.begin() , B.end() , greater<int>());
            ans = max(ans , sum);
            for (k = 0 ; k < K && k < A.size() && k < B.size(); ++ k) {
                sum -= A[k] , sum += B[k];
                ans = max(ans , sum);
            }
        }
    }
    printf("%d\n" , ans);
}

int main(){
        work();
    return 0;
}