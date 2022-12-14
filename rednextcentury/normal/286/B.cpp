#include <bits/stdc++.h>
using namespace std;
int n;
int a[3000001];
int b[3000001];
void f(int k)
{
    int st = k-1;
    int en = st+n-1;
    int extra = n%k;
    int last = en+1;
    for (int i=st;i<=en;i+=k)
    {
        b[min(last,i+k)]=a[i];
    }
    for (int i=st;i<=en+1;i+=k)
    {
        a[i]=b[i];
    }
    a[last] = b[last];
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        a[i]=i;
    for (int i=2;i<=n;i++)
        f(i);
    for (int i=n;i<2*n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}