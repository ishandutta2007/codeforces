#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i = 0; i < N; ++ i)
    {
        cin>>A[i];
        A[i]--;
    }
    vector<int> Ans(N);
    for(int i = 0; i < N; ++ i)
    {
        vector<int> Cnt(N);
        int maxx = 0;
        int best = -1;
        for(int j = i; j < N; ++ j)
        {
            Cnt[A[j]]++;
            if (Cnt[A[j]] > maxx)
            {
                maxx = Cnt[A[j]];
                best = A[j];
            }
            else if (Cnt[A[j]] == maxx)
            {
                best = min(A[j], best);
            }
            Ans[best]++;
        }
    }
    for(int i = 0; i < N; ++ i)
    {
        cout<<Ans[i]<<' ';
    }

}