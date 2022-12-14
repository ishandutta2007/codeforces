# include <iostream>
# include <algorithm>
# include <map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long sum=0;
    long long sum2=0;
    for (int i=0;i<n;i++)
    {
        long long c;
        cin>>c;
        sum+=c;
    }
    for (int i=0;i<n-1;i++)
    {
        long long c;
        cin>>c;
        sum-=c;
        sum2+=c;
    }
    for (int i=0;i<n-2;i++)
    {
        long long c;
        cin>>c;
        sum2-=c;
    }
    cout<<sum<<endl<<sum2<<endl;
}