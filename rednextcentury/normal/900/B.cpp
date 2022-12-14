
#include <bits/stdc++.h>
using namespace std;
int x[1000000];
int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    for (int i=1;i<=100000;i++)
    {
        a*=10;
        if (a/b == c)
        {
            cout<<i<<endl;
            return 0;
        }
        a=a%b;
    }
    cout<<-1<<endl;
}