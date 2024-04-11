#include<bits/stdc++.h>
using namespace std;
bool prime(int x)
{
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
            return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    int h=n;
    while(!prime(h))h--;
    int x=n-h;
    if (x==0)
        cout<<1<<endl<<h<<endl;
    else
    {
        if (prime(x))
            cout<<2<<endl<<h<<' '<<x<<endl;
        else
        {
            for (int i=2;i<x;i++)
            {
                if (prime(i) && prime(x-i))
                {
                    cout<<3<<endl<<i<<' '<<x-i<<' '<<h<<endl;
                    return 0;
                }
            }
        }
    }
}