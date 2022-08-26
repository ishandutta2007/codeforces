#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>


using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int N;
    cin>>N;
    vector<string> A(N);
    for(int i = 0; i < N; ++ i)
    {
        cin>>A[i];
    }
    if (N == 1)
    {
        cout<<6<<endl;
        return 0;
    }
    int k = 1179179;
    for(int i = 0; i < N; ++ i)
    {
        for(int j = i + 1; j < N; ++j)
        {
            int cnt = 0;
            for(int u = 0; u < 6; ++u)
            {
                if (A[i][u] != A[j][u])
                {
                    cnt++;
                }
            }
            //cout<<cnt<<' ';
            k = min(k, (cnt+1)/2);
        }
        //cout<<endl;
    }
    cout<<k-1<<endl;
}