#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
string value[1000000];
int num=0;
int n,m;
vector<int> original;
vector<char> op;
vector<int> op1;
vector<int> op2;
void getInput()
{
    scanf("%d%d",&n,&m);
    string nope(m,'?');
    mp[nope]=100000;
    value[100000]="-1";
    for (int i=0;i<n;i++)
    {
        string a,b,bb;
        cin>>a>>bb>>b;
        mp[a]=num++;
        if (b[0]!='0' && b[0]!='1')
        {
            string c,d;
            cin>>c>>d;
            if (b=="?")
                b=nope;
            if (d=="?")
                d=nope;
            op.push_back(c[0]);
            op1.push_back(mp[b]);
            op2.push_back(mp[d]);
            original.push_back(mp[a]);
            value[mp[a]]=nope;
        }
        else
        {
            value[mp[a]]=b;
        }
    }
}
string ret1,ret2;
int DoOp(int a,char p,int b)
{
    if (p=='X')return a^b;
    if (p=='A')return a&b;
    if (p=='O')return a|b;
}
void solve(int x)
{
    int num1=0,num2=0;
    for (int i=0;i<op.size();i++)
    {
        int a,b;
        if (op1[i]==100000)
            a=0;
        else
            a=value[op1[i]][x]-'0';
        if (op2[i]==100000)
            b=0;
        else
            b=value[op2[i]][x]-'0';
        int l=DoOp(a,op[i],b);
        value[original[i]][x]=l;
        num1+=l;
    }
    for (int i=0;i<op.size();i++)
    {
        int a,b;
        if (op1[i]==100000)
            a=1;
        else
            a=value[op1[i]][x]-'0';
        if (op2[i]==100000)
            b=1;
        else
            b=value[op2[i]][x]-'0';
        int l=DoOp(a,op[i],b);
        value[original[i]][x]=l;
        num2+=l;
    }
    if (num1==num2)
    {
        ret1+="0";
        ret2+="0";
    }
    else if (num1<num2)
        ret1+="0",ret2+="1";
    else
        ret1+="1",ret2+="0";
}
int main()
{
    getInput();
    for (int i=0;i<m;i++)
        solve(i);
    cout<<ret1<<endl<<ret2<<endl;
}