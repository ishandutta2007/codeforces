#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long s1=0;
    long long s2=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s1|=x;
    }
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s2|=x;
    }
    cout<<s1+s2<<endl;
}