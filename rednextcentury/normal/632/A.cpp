#include<bits/stdc++.h>
using namespace std;
string s[10000];
int main()
{
    long long n,p;
    cin>>n>>p;
    long long apples=0,half=0;
    long long given=0;
    for (int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for (int i=n-1;i>=0;i--)
    {
        if (s[i]=="half")
        {
            apples*=2;
        }
        else
        {
            given++;
            half++;

            if (half==2)
                apples++,half=0;
            half*=2;

            apples*=2;
            if (half==2)
                apples++,half=0;
        }
    }
    cout<<apples*p+half*p/2-given*p/2<<endl;
}