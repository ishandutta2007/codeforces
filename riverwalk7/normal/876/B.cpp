#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 100100
using namespace std;
int K, N, M;
int a;
vector<int> x[MAXN];
int main()
{
    cin>>N>>K>>M;
    for(int i=0; i<N; i++)
    {
        cin>>a;
        x[a%M].push_back(a);
    }
    for(int i=0; i<MAXN; i++)
    {
        if(x[i].size()>=K)
        {
            cout<<"Yes"<<endl;
            for(int j=0; j<K-1; j++)
            {
                cout<<x[i][j]<<" ";
            }
            cout<<x[i][K-1]<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}