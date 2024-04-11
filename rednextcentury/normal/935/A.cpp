#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin>>n;
    int ret=0;
    for (int i=1;i<n;i++)
    {
        if ((n-i)%i==0)

            ret++;
    }
    cout<<ret<<endl;
    return 0;
}