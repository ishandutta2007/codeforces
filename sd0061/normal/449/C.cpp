#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

const int N = 100005;
int n;
bool f[N] , v[N];
int s[N];

void work() {
    int i , j;
    scanf("%d",&n);
    f[0] = f[1] = 1;
    for (i = 2 ; i * i <= n ; ++ i) if (!f[i])
        for (j = i * i ; j <= n ; j += i) f[j] = 1;
    for (i = 1 ; i <= n ; ++ i)
        s[i] = s[i + 1] + !f[i];
    vector< pair<int , int> > res;
    for (i = n / 2 ; i >= 2 ; -- i) {
        if (!f[i]) {
            vector<int> Vec;
            for (j = i ; j <= n ; j += i)
                if (!v[j])
                    Vec.push_back(j);
            for (j = Vec.size() - 1 ; j - 1 >= 0 ; j -= 2) {
                int x = Vec[j] , y = Vec[j - 1];
                if (j == 2)
                    y = Vec[j - 2];
                res.push_back(make_pair(x , y));
                v[x] = v[y] = 1;
            }
        }
    }
    printf("%d\n" , res.size());
    for (i = 0 ; i < res.size() ; ++ i)
        printf("%d %d\n" , res[i].first , res[i].second);
}

int main()
{
    work();
    return 0;
}