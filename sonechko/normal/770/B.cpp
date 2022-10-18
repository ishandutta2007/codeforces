#include<bits/stdc++.h>
using namespace std;
int ans;
string res;
void gets(string t)
{
    string g="";
    int p=0;
    for (int i=0; i<t.size(); i++)
    if (p==1||t[i]!='0') {p=1; g+=t[i];}
    t=g;
    int sum=0;
    for (int i=0; i<t.size(); i++)
    {
        sum+=(t[i]-'0');
    }
    if (sum>ans) {ans=sum;res=t;} else
    if (sum==ans&&(t.size()>res.size()||(t.size()==res.size()&&t>res))) {ans=sum; res=t;}
}
int main()
{
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]!='0')
        {
            string t="";
            for (int j=0; j<i; j++)
            t+=s[j];
            int k=(s[i]-'0'-1);
            char ch=(k+'0');
            t+=ch;
            for (int j=i+1; j<s.size(); j++)
                t+="9";
            gets(t);
        }
    }
    gets(s);
    cout<<res<<endl;
}