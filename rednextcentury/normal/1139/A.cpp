#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    int n;
    cin>>n;
    cin>>s;
    long long num=0;
    for (int i=0;i<s.size();i++)
    {
        if ((s[i]-'0')%2==0)num+=i+1;
    }
    cout<<num<<endl;
}