#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int cur=0;
    int ret=0;
    int A=0;
    for (int i=0;i<s.size();i++)
    {
        int B=0;
        int totA=0;
        for (int j=i;j<s.size();j++)
        {
            totA+=(s[j]=='a');
        }
        for (int j=i;j<s.size();j++)
        {
            B+=(s[j]=='b');
            totA-=(s[j]=='a');
            ret=max(ret,A+totA+B);
        }
        A+=(s[i]=='a');
    }
    cout<<max(max(A,n-A),ret)<<endl;
}