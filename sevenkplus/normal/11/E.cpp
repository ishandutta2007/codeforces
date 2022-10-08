#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
#define N 1000010
char t[N];
int cc(string s)
{
    int n=s.size(),p=0,q=0,o=0,f=0;
    char w;
    for(int i=0;i<n;i++)
    {
        w=(q&1)?'R':'L';
        if(s[i]=='X')
            q++;
        else
            if(s[i]==w)
                p++,q++,f=0;
            else
                p++,q+=2,o+=f,f=!f;
    }
    if(q&1)
        q++,o+=f;
    if(p*2>q)
        p-=o,q-=o*2;
    return (ll)p*100000000/q;
}
int main()
{
    string s="";
    scanf("%s",t);
    int n=strlen(t);
    for(int i=0;i<n;i++)
    {
        if(i>0&&t[i]==t[i-1]&&t[i]!='X')
            s+='X';
        s+=t[i];
    }
    int R;
    if(s[0]==s[s.size()-1]&&s[0]!='X')
        R=max(cc(s+'X'),cc('X'+s));
    else
        R=cc(s);
    printf("%d.%06d\n",R/1000000,R%1000000);
    return 0;
}