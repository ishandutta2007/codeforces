#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define N 205
int n , a[N] , ans[N];
vector<int> cnt[N];
vector<int> A[2] , B , C;
bool f[N];
int main()
{
    //freopen("~input.txt" , "r" , stdin);
    int i , j , s = 0 , t = 0 , x;
    cin >> n; n <<= 1;
    for (i = 0 ; i < n && t < n; ++ i)
        cin >> a[i] , cnt[a[i]].push_back(i);
    for (i = 10 ; i <= 99 ; ++ i)
    {
        if (cnt[i].size() % 2 == 0)
        {
            for (j = 0 ; j < cnt[i].size() && t < n ; ++ j)
            {
                A[s].push_back(i);
                ans[cnt[i][j]] = s;
                s ^= 1 , ++ t;
            }
        }
        if (cnt[i].size() == 1)
            B.push_back(cnt[i][0]);
        else if (cnt[i].size() > 1)
        {
            A[s].push_back(i);
            ans[cnt[i][0]] = s , s ^= 1;
            A[s].push_back(i);
            ans[cnt[i][1]] = s , s ^= 1;
            for (j = 2 ; j < cnt[i].size() ; ++ j)
                C.push_back(cnt[i][j]);
        }
    }
    for (i = 0 ; i < B.size() ; ++ i)
    {
        A[s].push_back(a[B[i]]);
        ans[B[i]] = s , s ^= 1;
    }
    for (i = 0 ; i < C.size() ; ++ i)
    {
        A[s].push_back(a[C[i]]);
        ans[C[i]] = s , s ^= 1;
    }


    sort(A[0].begin() , A[0].end());
    sort(A[1].begin() , A[1].end());
    A[0].resize(unique(A[0].begin() , A[0].end()) - A[0].begin());
    A[1].resize(unique(A[1].begin() , A[1].end()) - A[1].begin());
    cout << A[0].size() * A[1].size() << endl;
    for (i = 0 ; i < n ; ++ i)
        cout << ans[i] + 1 << ' ';
    //cout << "Hello world!" << endl;
    return 0;
}