# include <bits/stdc++.h>
using namespace std;
string ret[1000001];
void sol1(string s)
{
    int a=0,b=0;
    int i;
    for (i=1;s[i]!='C';i++)
        a=a*10+s[i]-'0';
    i++;
    for (;i<s.size();i++)
        b=b*10+s[i]-'0';
    cout<<ret[b]<<a<<endl;
}
void sol2(string s)
{
    int a=0,b=0;
    int i;
    for (i=0;!isdigit(s[i]);i++)
        a=a*26+s[i]-'A'+1;
    for (;i<s.size();i++)
        b=b*10+s[i]-'0';
    cout<<'R'<<b<<'C'<<a<<endl;
}
char cur[1000];
void Add()
{
    int l=0;
    while(cur[l]=='Z')
    {
        cur[l]='A';
        l++;
    }
    if (cur[l]>='A' && cur[l]<='Z')
        cur[l]++;
    else
        cur[l]='A';

}
void init()
{
    cur[0]='A';
    ret[1]=cur;
    for (int i=2;i<=1000000;i++)
        Add(),ret[i]=cur,reverse(ret[i].begin(),ret[i].end());
}
int main()
{
    init();
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        bool is=0;
        if (s[0]=='R' && isdigit(s[1]))
        {
            for (int i=2;i<s.size();i++)
            {
                if (s[i]=='C')
                    is=1;
            }
        }
        if (is)
            sol1(s);
        else
            sol2(s);
    }
}