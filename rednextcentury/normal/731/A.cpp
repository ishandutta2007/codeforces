#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    char last='a';
    int ret=0;
    for (int i=0;i<s.size();i++)
    {
        ret+=min(abs(s[i]-last),26-abs(s[i]-last));
        last=s[i];
    }
    cout<<ret<<endl;
}