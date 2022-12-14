#include <bits/stdc++.h>
using namespace std;
int num[100];
int ret;
int main ()
{
    int k;
    cin>>k;
    string s;
    cin>>s;
    int sum=0;
    for (int i=0;i<s.size();i++)
    {
        num[s[i]-'0']++;
        sum+=s[i]-'0';
    }
    sort(s.begin(),s.end());
    for (int i=0;i<s.size();i++)
    {
        if (sum>=k)
        {
            cout<<i<<endl;
            return 0;
        }
        sum+='9'-s[i];
    }
    cout<<s.size()<<endl;
}