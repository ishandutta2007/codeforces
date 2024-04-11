// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 74;
int n, A[3][N], M[N], P[N];
vector < int > U;
vector < pair < int , int > > V[N];
map < int , vector < pair < int , int > > > MP[N];
inline int GetId(int a)
{
    return ((int)(lower_bound(U.begin(), U.end(), a) - U.begin()));
}
inline bool CMP(int i, int j)
{
    return (A[0][i] < A[0][j]);
    //return make_tuple(A[0][i], A[1][i], A[2][i]) < make_tuple(A[0][j], A[1][j], A[2][j]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d%d%d", &A[0][i], &A[1][i], &A[2][i]);
        U.push_back(A[0][i]);
        U.push_back(A[1][i]);
        U.push_back(A[2][i]);
    }
    sort(U.begin(), U.end());
    U.resize(unique(U.begin(), U.end()) - U.begin());
    for (int i = 1; i <= n; i ++)
    {
        A[0][i] = GetId(A[0][i]);
        A[1][i] = GetId(A[1][i]);
        A[2][i] = GetId(A[2][i]);
    }
    for (int x = 0; x <= 2; x ++)
        for (int y = 0; y <= 2; y ++)
            for (int z = 0; z <= 2; z ++)
                if (x != y && y != z && z != x)
                {
                    for (int i = 1; i <= n; i ++)
                        if (!M[i])
                            MP[A[x][i]][A[y][i]].push_back({A[z][i], i});
                    for (int i = 0; i < N; i ++)
                    {
                        for (auto ele : MP[i])
                        {
                            vector < pair < int , int > > vec = ele.second;
                            sort(vec.begin(), vec.end());
                            for (int j = 1; j < (int)vec.size(); j += 2)
                            {
                                M[vec[j - 1].second] = M[vec[j].second] = 1;
                                printf("%d %d\n", vec[j - 1].second, vec[j].second);
                            }
                        }
                        MP[i].clear();
                    }
                }
    for (int x = 0; x <= 2; x ++)
        for (int y = 0; y <= 2; y ++)
            for (int z = 0; z <= 2; z ++)
                if (x != y && y != z && z != x)
                {
                    for (int i = 1; i <= n; i ++)
                        if (!M[i]) V[A[x][i]].push_back({A[y][i], i});
                    for (int i = 0; i < N; i ++)
                    {
                        sort(V[i].begin(), V[i].end());
                        for (int j = 1; j < (int)V[i].size(); j += 2)
                        {
                            M[V[i][j - 1].second] = M[V[i][j].second] = 1;
                            printf("%d %d\n", V[i][j - 1].second, V[i][j].second);
                        }
                        V[i].clear();
                    }
                }
    int ts = 0;
    for (int i = 1; i <= n; i ++)
        if (!M[i]) P[ts ++] = i;
    sort(P, P + ts, CMP);
    for (int i = 0; i < ts; i += 2)
        printf("%d %d\n", P[i], P[i + 1]);
    return 0;
}