#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define P 1000000009
int n,m,S,c,L;
set<string>a,e;
map<string,int>p;
int q[111],w[111][4];
int f[1111][111][11];
char chr(int p){static char c[4]={'A','C','G','T'};return c[p];}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        string s;cin>>s;
        L=max(L,(int)s.length());
        e.insert(s);
        for(int j=0;j<s.length();j++)
            a.insert(s.substr(0,j+1));
    }
    a.insert("");
    for(set<string>::iterator i=a.begin();i!=a.end();i++)p[*i]=c++;
    for(set<string>::iterator i=a.begin();i!=a.end();i++)
        for(set<string>::iterator j=e.begin();j!=e.end();j++)
            if(i->length()>=j->length()&&i->substr(i->length()-j->length())==*j)
                q[p[*i]]=max(q[p[*i]],(int)j->length());
    for(set<string>::iterator i=a.begin();i!=a.end();i++)
        for(int x=0;x<4;x++)
        {
            string y=(*i)+chr(x);
            while(a.find(y)==a.end())y=y.substr(1);
            w[p[*i]][x]=p[y];
        }
    f[0][p[""]][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<c;j++)
            for(int k=0;k<L;k++)
                if(f[i][j][k])
                    for(int l=0;l<4;l++)
                    {
                        int o=(q[w[j][l]]>=k+1)?0:(k+1);
                        if(o<=L)f[i+1][w[j][l]][o]=(f[i+1][w[j][l]][o]+f[i][j][k])%P;
                    }
    for(int i=0;i<c;i++)S=(S+f[n][i][0])%P;
    printf("%d\n",S);
    return 0;
}