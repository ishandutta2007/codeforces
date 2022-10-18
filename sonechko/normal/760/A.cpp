#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int p=31;
    if (n==2) p=28;
    if (n==4||n==6||n==9|n==11) p=30;
    int kol=0,pr=m;
    for (int i=1; i<=p; i++)
    {
        if (kol==0&&pr==m) kol++; else
        if (pr==1) kol++;
        pr++;
        if (pr==8) pr=1;
    }
    cout<<kol<<endl;
}