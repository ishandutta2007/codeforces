#include<bits/stdc++.h>
using namespace std;
unsigned long long ret[1000000];
int main()
{
    long long n;
    cin>>n;
    ret[0]=1;
    ret[1]=2;
    for (int i=1;i<=2000;i++)
    {
        if (i>1)
            ret[i]=ret[i-1]+ret[i-2];
        if (ret[i]>n)
        {
            cout<<i-1<<endl;
            return 0;
        }
    }
}