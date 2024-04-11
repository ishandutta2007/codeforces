#include<bits/stdc++.h>
using namespace std;
string toString(long long x)
{
    string ret="";
    do
    {
        ret+=char('0'+(x%10));
        x/=10;
    }while(x);
    reverse(ret.begin(),ret.end());
    return ret;
}
int Try(string a,string b)
{
    if (a.size()<b.size())return 1e9;
    int cur=0;
    for (int i=0;i<a.size();i++)
    {
        if (cur==b.size())break;
        if (a[i]==b[cur])cur++;
    }
    if (cur==b.size())return a.size()-b.size();
    else return 1e9;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int ret=1e9;
    for (long long i=1;i<=100000;i++)
    {
        ret=min(ret,Try(s,toString(i*i)));
    }
    if (ret>=1e8)cout<<-1<<endl;
    else cout<<ret<<endl;
}