#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ret="";
    int c=2;
    for (int i=0;i<s.size();)
    {
        ret+=s[i];
        i+=c;
        c++;
    }
    cout<<ret<<endl;
}