#include <iostream>
using namespace std;
bool dp[200][20][10];
int main()
{
    int n,t;
    cin>>n>>t;
    int x=1;
    for (int i=2;i<=10;i++)
        x*=i;
    if (n<7)
    {
        int l=1;
        for (int i=0;i<n-1;i++)
            l*=10;
        int r=l*10;
        for (int i=l;i<r;i++)
        {
            if (i%t==0)
            {
                cout<<i<<endl;
                return 0;
            }
        }
        cout<<-1<<endl;
    }
    else
    {
        cout<<x;
        for (int i=0;i<n-7;i++)
            cout<<0;
        cout<<endl;
    }
}