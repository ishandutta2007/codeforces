#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 300005;
int n , a[N];
LL s[N];
map<int , int> L , R;
void work() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        s[i] = s[i - 1] + max(0 , a[i]);
        R[a[i]] = i;
    }
    for (int i = n ; i > 0 ; -- i)
        L[a[i]] = i;
    LL res = -1LL << 60;
    int ll , rr;
    for (auto &it : L) {
        int x = it.first;
        int l = it.second , r = R[x];
        LL val = s[r - 1] - s[l] + a[l] + a[r];
        if (l != r && val > res) {
            res = val;
            ll = l , rr = r;
        }
    }
    vector<int> cut;
    for (int i = 1 ; i < ll ; ++ i)
        cut.push_back(i);
    for (int i = ll + 1 ; i < rr ; ++ i)
        if (a[i] < 0)
            cut.push_back(i);
    for (int i = rr + 1 ; i <= n ; ++ i)
        cut.push_back(i);    
    printf("%lld %d\n" , res , (int)cut.size());
    for (int i = 0 ; i < (int)cut.size() ; ++ i)
        printf("%d " , cut[i]);
}

int main() {
    work();
    return 0;
}