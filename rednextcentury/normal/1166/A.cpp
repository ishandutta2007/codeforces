#include <bits/stdc++.h>
using namespace std;
long long num[100];
long long Get(long long x)
{
    return x*(x-1)/2;
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        num[s[0]-'a']++;
    }
    long long ret=0;
    for (int i=0;i<26;i++)
    {
        ret+=Get(num[i]/2)+Get(num[i]/2 + num[i]%2);
    }
    cout<<ret<<endl;
}