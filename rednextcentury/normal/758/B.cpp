#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int num[10000];
int p[10000];
string k="RBYG";
int main()
{
    fast_io
    string s;
    cin>>s;
    int n=s.size();
    for (int i=0;i<n;i++)
    {
        if (s[i]=='!')
            num[i%4]++;
        else
        {
            p[s[i]-'A']=i%4;
        }
    }
    for (int i=0;i<4;i++)
        cout<<num[p[k[i]-'A']]<<' ';
    cout<<endl;
}