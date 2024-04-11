#include<bits/stdc++.h>
using namespace std;
map<string,int> val;
int getVal(string x)
{
    int num = 0;
    int l=0,r=x.size()-1;
    while(x[l]=='&')
        l++,num--;
    while(x[r]=='*')
        r--,num++;
    x=x.substr(l,(r-l+1));
    if (val[x]<=0)
        return 0;
    return val[x]+num;
}
string s[10001];
void printVal(string x)
{
    int num = 0;
    int l=0,r=x.size()-1;
    while(x[l]=='&')
        l++,num--;
    while(x[r]=='*')
        r--,num++;
    x=x.substr(l,(r-l+1));
    if (val[x]<=0)
        num=-1000000;
    num+=val[x];
    if (num<0)num=0;
    if (num==0)
        cout<<"errtype"<<endl;
    else
        cout<<s[num]<<endl;
}
int main()
{
    int n;
    cin>>n;
    string x = "void";
    val[x]=1;
    s[1]=x;
    for (int i=2;i<=3000;i++)
        s[i]=s[i-1]+"*";
    while(n--)
    {
        string a,b,c;
        cin>>a;
        if (a=="typedef")
        {
            cin>>b>>c;
            val[c] = getVal(b);
        }
        else
        {
            cin>>b;
            printVal(b);
        }
    }
}