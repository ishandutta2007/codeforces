#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
    int a[1000];
int main ()
{
    int sum=0;
    for (int i=0;i<5;i++)
    {
        int x;
        cin>>x;
        a[x]++;
        sum+=x;
    }
    int best=sum;
    for (int i=100;i>=0;i--)
    {
        if (a[i]>=3)
        {
            best=min(best,sum-i*3);
        }

        if (a[i]>=2)
        {
            best=min(best,sum-i*2);
        }
    }
    cout<<best<<endl;
}