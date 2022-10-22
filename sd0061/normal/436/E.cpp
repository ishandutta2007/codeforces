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
using namespace std;
typedef long long LL;
#define N 300005
int n , w , res[N];
pair<int , int> a[N];
vector< pair<int , int> > A;
vector< int > B;
pair<int , int> f[N] , g[N];
LL s1[N << 1] , s2[N];
bool cmp(int x , int y) {
    if (a[x].second != a[y].second)
        return a[x].second < a[y].second;
    return a[x].second - a[x].first > a[y].second - a[y].first;
}

void work()
{
    int i , j ;
    scanf("%d%d",&n,&w);
    for (i = 1 ; i <= n ; ++ i) {
        int x , y;
        scanf("%d%d",&x,&y);
        a[i] = make_pair(x , y);
        if (x <= y - x) {
            A.push_back(make_pair(x , i));
            A.push_back(make_pair(y - x , i));
        } else {
            B.push_back(i);
        }
    }
    LL x , y;
    sort(A.begin() , A.end());
    sort(B.begin() , B.end() , cmp);
    for (i = 0 ; i < A.size() ; ++ i)
        s1[i + 1] = s1[i] + A[i].first;
    f[0] = make_pair(-1 << 30 , -1);
    for (i = 0 ; i < B.size() ; ++ i) {
        f[i + 1] = max(f[i] , make_pair(a[B[i]].second - a[B[i]].first , B[i]));
        s2[i + 1] = s2[i] + a[B[i]].second;
    }
    g[B.size()] = make_pair(1 << 30 , -1);
    for (i = B.size() - 1 ; i >= 0 ; -- i)
        g[i] = min(g[i + 1] , make_pair(a[B[i]].first , B[i]));
    pair<LL , int> ans(1LL << 60 , -1);
    for (i = 0 ; i <= w && i <= A.size() ; ++ i) {
        LL sum = s1[i];
        j = w - i;
        if ((j + 1) / 2 > B.size()) continue;
        if (j % 2 == 0) {
            sum += s2[j / 2];
        } else {
            x = s2[j + 1 >> 1] - f[j + 1 >> 1].first;
            y = s2[j >> 1] + g[j + 1 >> 1].first;
            sum += min(x , y);
        }
        ans = min(ans , make_pair(sum , i));
    }
    cout << ans.first << endl;
    j = w - ans.second;
    for (i = 0 ; i < ans.second ; ++ i)
        ++ res[A[i].second];
    if (j % 2 == 0) {
        for (i = 0 ; i < j >> 1 ; ++ i)
            res[B[i]] += 2;
    } else {
        x = s2[j + 1 >> 1] - f[j + 1 >> 1].first;
        y = s2[j >> 1] + g[j + 1 >> 1].first;
        if (x < y) {
            for (i = 0 ; i < (j + 1) >> 1 ; ++ i)
                res[B[i]] += 2;
            -- res[f[(j + 1) >> 1].second];
        } else {
            for (i = 0 ; i < j >> 1 ; ++ i)
                res[B[i]] += 2;
            ++ res[g[(j + 1) >> 1].second];
        }
    }
    for (i = 1 ; i <= n ; ++ i)
        printf("%d" , res[i]);
}

int main()
{
    work();
    return 0;
}