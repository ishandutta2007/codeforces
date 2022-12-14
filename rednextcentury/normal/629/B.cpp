#include <bits/stdc++.h>
using namespace std;
int a[1000];
int b[1000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        char x;
        cin>>x;
        int s,e;
        cin>>s>>e;
        if (x=='F')a[s]++,a[e+1]--;
        else b[s]++,b[e+1]--;
    }
    int numA=0,numB=0;
    int ans=0;
    for (int i=0;i<=400;i++)
    {
        numA+=a[i];
        numB+=b[i];
        ans=max(ans,min(numA,numB));
    }
    cout<<2*ans<<endl;
}