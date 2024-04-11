#include<Bits/stdc++.h>
using namespace std;

const int N = 1e5 + 11;

int a[N];

int main()
{
    int n;
    cin>>n;
    int res1=0,res2=0;
    for (int i=1; i<=n/2; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n/2+1);
    for (int i=1; i<=n/2; i++)
    {
        int l=a[i];
        res1+=abs(l-(i*2-1));
        res2+=abs(l-i*2);
    }
    cout<<min(res1,res2)<<"\n";
}