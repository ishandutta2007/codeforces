#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
map<string,int> macro;
bool only[200],single[200],bad[200];
int nm,n,t;
char buf[505],ontype[255];
string getNext(int l)
{
	string s="";
	if(buf[l]=='(')
	{
		int z=1;
		s+=buf[l++];
		for(;z;l++)
		{
			s+=buf[l];
			if(buf[l]=='(')
				z++;
			if(buf[l]==')')
				z--;
		} 
		return s;
	}
	for(;buf[l]!='*'&&buf[l]!='-'&&buf[l]!='+'&&buf[l]!='/'&&buf[l]&&buf[l]!=')';++l)
		s+=buf[l];
	return s;
}
bool badExpression(int l,int r,int cMacro=0) 
{
    char pop='x';
    char nop='x';
    bool gadd=0;
    bool nsingle=0;
    while(l<=r) 
	{
        if(nop=='+'||nop=='-')
            gadd=1;
        pop=nop;
        string s=getNext(l);
        l+=s.size();
        if(l<=r)
            nop=buf[l];
        else
            nop='x';
        if(s[0]=='(') 
		{
            if(badExpression(l-s.size()+1,l-2))
                return 1;
        } 
		else 
		{
            int c=macro[s];
            if(c>0) 
			{
                gadd|=!only[c];
                nsingle|=!single[c];
                if(bad[c])
                    return 1;
                if((pop=='*'||nop=='*'||nop=='/'||pop=='-')&&!only[c])
                    return 1;
                if(pop=='/'&&!single[c])
                    return 1;
            }
        }
        ++l;
    }
    if(cMacro)
	{
        only[cMacro]=!gadd;
        single[cMacro]=bool(pop=='x'&&!nsingle);
    }
    return 0;
} 
void addMacro() 
{
    int l=0,r=strlen(buf);
    while(buf[l]!='n')
        ++l;
    l+=2;
    while(buf[l]==' ')
        ++l;
    string name="";
    while(buf[l]!=' ')
        name+=buf[l++];
    int z=0;
    for(int i=l;i<r;++i)
        if(buf[i]!=' ')
            buf[z++]=buf[i];
    l=0,r=z;
    buf[r]=0;
    ++nm;
    bad[nm]=badExpression(l,r,nm);
    int cnt=0;
    macro[name]=nm;
}
char final[]="#define % ";
signed main() 
{
    t=read();
	while(t--) 
	{
        gets(buf);
        addMacro();
    }
    for(int i=0;i<10;i++)
        buf[i]=final[i];
    gets(buf+10);
    addMacro();
    cout<<(bad[nm]?"Suspicious\n":"OK\n");
}