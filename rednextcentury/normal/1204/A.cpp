#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int zero=0;
    int num=0;
    for (int i=1;i<s.size();i++)
        num++,zero+=(s[i]=='0');
    int ret=num/2+1;
    if (num==zero && num%2==0)ret--;
    cout<<ret<<endl;
}