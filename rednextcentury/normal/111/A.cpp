#include<iostream>
# include <iomanip>
using namespace std;
int main()
{
    long long n,x,y;
    cin>>n>>x>>y;
    swap(x,y);
    if ((n>x) || (n-1)+(x-n+1)*(x-n+1)<y)
    {
        cout<<-1<<endl;
        return 0;
    }
    for (int i=0;i<n-1;i++)
        cout<<1<<endl;
    cout<<x-n+1<<endl;
}