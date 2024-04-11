#include <iostream>
using namespace std;
int N, K;
int sum, total;
int x;
int ans;
int main()
{
    cin>>N>>K;
    for(int i=0; i<N; i++)
    {
        cin>>x;
        sum += x;
        total++;
    }
    while(sum < K*total-total/2)
    {
        sum+=K;
        ans++;
        total++;
    }
    cout<<ans<<endl;
}