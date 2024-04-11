#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<string,int>O;
map<char,int>P;
char s[1000];
string S,T;
int ff(int l,int r)
{
    int i,x=0;
    for(i=r;i>=l;i--)
    {
        x+=P[s[i]];
        if(!x&&(s[i]=='+'||s[i]=='-'))
        {
            int vl=ff(l,i-1),vr=ff(i+1,r);
            return (vl==-2||vr==-2||(s[i]=='-'&&vr==2))?-2:2;
        }
    }
    for(x=0,i=r;i>=l;i--)
    {
        x+=P[s[i]];
        if(!x&&(s[i]=='*'||s[i]=='/'))
        {
            int vl=ff(l,i-1),vr=ff(i+1,r);
            return (vl==-2||vr==-2||vl==2||vr==2||(s[i]=='/'&&vr==1))?-2:1;
        }
    }
    if(s[l]=='(')
        return (ff(l+1,r-1)==-2)?-2:-1;
    T="";
    for(i=l;i<=r;i++)
        T+=s[i];
    return O.count(T)?O[T]:-1;
}
int main()
{
    O.clear();
    P.clear(),P['(']=1,P[')']=-1;
    int n;
    for(scanf("%d",&n),gets(s),n++;n--;)
    {
        if(n)
        {
            scanf("%s",s);
            if(s[1]!='d')
                scanf("%s",s);
            scanf("%s",s);
            S=s;
        }
        gets(s);
        int l=0;
        for(int i=0;s[i];i++)
            if(s[i]!=' '&&s[i]!=13)
                s[l++]=s[i];
        s[l]=0;
        int T=ff(0,l-1);
        if(n)
            O[S]=T;
        else
            puts(T==-2?"Suspicious":"OK");
    }
    return 0;
}