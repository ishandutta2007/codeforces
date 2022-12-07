#include <iostream>
#include <vector>
using namespace std;
int N, K;
vector<int> factors;
int main()
{
    cin>>N>>K;
    for(int i=2; i<=N; i++)
    {
        while(N%i==0&&K>=2)
        {
            N /= i;
            factors.push_back(i);
            K--;
        }
        if(N==1&&K!=0)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(K==1)
        {
            factors.push_back(N);
            K--;
        }
    }
    for(int i=0; i<factors.size(); i++)
    {
        cout<<factors[i]<<" ";
    }
    cout<<""<<endl;
}