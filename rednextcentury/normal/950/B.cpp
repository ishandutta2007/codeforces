#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int b[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=m;i++)
        cin>>b[i];
    int i=1,j=1;
    int L=a[1],R=b[1];
    int ret=0;
    while(1)
    {
        if (L==R)
        {
            ret++;
            L=0,R=0;
            i++;
            j++;
            if (i>n || j>m)break;
            L=a[i],R=b[j];
        }
        else if (L<R)
        {
            i++;
            L+=a[i];
        }
        else
        {
            j++;
            R+=b[j];
        }
    }
    cout<<ret<<endl;
}