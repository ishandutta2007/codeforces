#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        a[i]=s.size();
    }
    sort(a,a+n);
    string s;
    cin>>s;
    int x=s.size();
    int num=0;
    int r1=1000000;
    int r2=1000000;
    for (int i=0;i<n;i++)
    {
        if (i%k==0 && i!=0) num+=5;
        if (a[i]==x)r1=min(r1,num+1),r2=num+1;
        num++;
    }
    cout<<r1<<' '<<r2<<endl;
}