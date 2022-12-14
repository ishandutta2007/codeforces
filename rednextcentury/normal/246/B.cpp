#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int n;
    cin>>n;
    int sum=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
    }
    if (abs(sum)%n==0)
        cout<<n<<endl;
    else
        cout<<n-1<<endl;
}