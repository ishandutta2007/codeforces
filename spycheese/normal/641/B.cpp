#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>


using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int N, M, Q;
    cin>>N>>M>>Q;
    vector<vector<pair<int, int> > > Real(N, vector<pair<int, int> > (M));
    vector<vector<int> > B(N, vector<int> (M));
    for(int i = 0; i < N; ++ i)
    {
        for(int j = 0; j < M; ++ j)
        {
            Real[i][j] = make_pair(i, j);
        }
    }
    for(int u = 0; u < Q; ++ u)
    {
        int z;
        cin>>z;
        if (z == 1)
        {
            int i;
            cin>>i;
            i--;
            pair<int, int> first = Real[i][0];
            for(int j = 0; j +1 < M; ++ j)
            {
                Real[i][j] = Real[i][j+1];
            }
            Real[i].back() = first;
        }
        if (z == 2)
        {
            int j;
            cin>>j;
            j--;
            pair<int, int> first = Real[0][j];
            for(int i = 0; i + 1 < N; ++ i)
            {
                Real[i][j] = Real[i+1][j];
            }
            Real[N-1][j] = first;
        }
        if (z == 3)
        {
            int i, j, x;
            cin>>i>>j>>x;
            i--;
            j--;
            int ii = Real[i][j].first;
            int jj = Real[i][j].second;
            B[ii][jj] = x;
        }
    }
    for(int i = 0; i < N; ++ i)
    {
        for(int j = 0; j < M; ++j)
        {
            cout<<B[i][j]<<' ';
        }
        cout<<endl;
    }

}