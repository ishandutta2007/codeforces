#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    string s;
    cin>>n>>s;
    int A=0;
    int sum=0;
    for (int i=0;i<n/2;i++)
    {
        if (s[i]=='?')A++;
        else sum+=(s[i]-'0');
    }
    int B=0;
    for (int i=n/2;i<n;i++)
    {
        if (s[i]=='?')B++;
        else sum-=(s[i]-'0');
    }
    int k = min(A,B);
    A-=k,B-=k;
    if (!A && !B)
    {
        if (sum==0)cout<<"Bicarp"<<endl;
        else cout<<"Monocarp"<<endl;
    }
    else if (A)
    {
        int nn = sum+9*(A/2);
        if (nn!=0)cout<<"Monocarp"<<endl;
        else cout<<"Bicarp"<<endl;
    }
    else if (B)
    {
        int nn = sum-9*(B/2);
        if (nn!=0)cout<<"Monocarp"<<endl;
        else cout<<"Bicarp"<<endl;
    }
}