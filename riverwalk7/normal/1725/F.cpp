#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;
int N, Q;
int L[MAXN], R[MAXN];
vector<int> b, e;
int ans[30];
int cur;
int W;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>L[i]>>R[i];
    }
    for(int i=1; i<(1<<30); i<<=1)
    {
        b.clear(); e.clear();
        for(int j=0; j<N; j++)
        {
            if(R[j] - L[j] + 1 >= i)
            {
                b.push_back(0); e.push_back(i-1);
            }
            else
            {
                if(R[j] % i < L[j] % i)
                {
                    b.push_back(0); e.push_back(R[j] % i);
                    b.push_back(L[j] % i); e.push_back(i-1);
                }
                else
                {
                    b.push_back(L[j] % i); e.push_back(R[j] % i);
                }
            }
        }
        sort(b.begin(), b.end());
        sort(e.begin(), e.end());
        int counter = 0;
        for(int j=0; j<b.size(); j++)
        {
            while(counter < e.size() && e[counter] < b[j])
            {
                ++counter;
            }
            ans[(int)(log2(i))] = max(ans[(int)(log2(i))], j-counter+1);
        }
    }
    cin>>Q;
    for(int i=0; i<Q; i++)
    {
        cin>>W;
        W = W & -W;
        cout<<ans[(int)(log2(W))]<<endl;
    }
}