// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
char A[N], B[N];
vector < int > vec[2];
int main()
{
    scanf("%d%s%s", &n, A, B);
    for (int i = 0; i < n; i ++)
        if (A[i] != B[i])
            vec[A[i] == 'b'].push_back(i);
    if ((vec[0].size() + vec[1].size()) & 1)
        return !printf("-1\n");
    vector < pair < int , int > > R;
    for (int w = 0; w <= 1; w ++)
        while (vec[w].size() > 1)
        {
            int i = vec[w].back(); vec[w].pop_back();
            int j = vec[w].back(); vec[w].pop_back();
            R.push_back({i, j});
        }
    if (vec[0].size())
    {
        int i = vec[0][0];
        int j = vec[1][0];
        R.push_back({i, i});
        R.push_back({i, j});
    }
    printf("%d\n", (int)R.size());
    for (auto X : R)
        printf("%d %d\n", X.first + 1, X.second + 1);
    return 0;
}