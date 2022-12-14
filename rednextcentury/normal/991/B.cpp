#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int n;
    cin>>n;
    int need = (n/2)*9 + (n%2)*5;
    for (int i=0;i<n;i++)
        cin>>a[i],need-=a[i];
    sort(a,a+n);
    int cur=0;
    for (int i=0;i<n;i++)
    {
        if (need<=0)
            break;
        cur++;
        need-=(5-a[i]);
    }
    cout<<cur<<endl;
}