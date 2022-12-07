#include <iostream>
#include <fstream>
#define MAXN 200200
using namespace std;
typedef long long ll;
int T, N; ll K;
int a[MAXN];
int S;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N>>K;
        S = -2e9;
        for(int j=0; j<N; j++)
        {
            cin>>a[j];
            S = max(S, a[j]);
        }
        for(int j=0; j<N; j++)
        {
            a[j] = S-a[j];
        }
        --K;
        S = -2e9;
        for(int j=0; j<N; j++)
        {
            S = max(S, a[j]);
        }
        if(K & 1)
        {
            for(int j=0; j<N; j++)
            {
                cout<<S-a[j]<<" ";
            }
        }
        else
        {
            for(int j=0; j<N; j++)
            {
                cout<<a[j]<<" ";
            }
        }
        cout<<""<<endl;
    }
}