#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll N, K;
vector<ll> factors;
ll triangular[300000];
int main()
{
    cin>>N>>K;
    for(int i=1; i<=300000; i++)
    {
        if(N%i==0)
        {
            factors.push_back(i);
            factors.push_back(N/i);
        }
    }
    for(int i=1; i<300000; i++)
    {
        triangular[i] = triangular[i-1] + (ll) i;
    }
    if(K*(K+1)/2>N||K>=300000)
    {
        cout<<-1<<endl;
        return 0;
    }
    sort(factors.begin(), factors.end());
    for(int i = factors.size() - 1; i>=0; i--)
    {
        if(triangular[K]*factors[i]<=N&&triangular[K/100]*factors[i]<=N)
        {
            for(int j=1; j<K; j++)
            {
                cout<<factors[i]*j<<" ";
                N-= (factors[i]*j);
            }
            cout<<N<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}