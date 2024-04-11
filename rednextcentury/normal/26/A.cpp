#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
int main()
{
    int n;
    cin>>n;
    int ret=0;
    for (int i=2;i<=n;i++)
    {
        int num=0;
        int x=i;
        for (int j=2;j<=i;j++)
        {
            if (x%j==0)num++;
            while(x%j==0)x/=j;
        }
        if (x!=1)num++;
        if (num==2)ret++;
    }
    cout<<ret<<endl;
}