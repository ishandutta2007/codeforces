/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-09 17:37:34
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot,cnt;
string str;
map<string,int> mp;
bool flag=false;
string ss[MAXN];
int r[MAXN];
int main()
{
    while(true)
    {
        if(!flag) 
        {
            cin>>str;
            n=str.size();
            if(n>6&&str.substr(0,6)=="\\begin")
            {
                flag=true;
                //puts("done");
                continue;
            }
            if(n>5&&str.substr(0,5)=="\\cite")
            {
                int pos=-1;
                for(int i=0;i<n;i++)
                {   
                    if(str[i]=='}')
                    {
                        pos=i;
                        break;
                    }
                }
                int len=pos-6;
               // printf("len=%d\n",len);
                string s=str.substr(6,len);
                mp[s]=++tot;
               // printf("%d ",tot);
               // cout<<s<<endl;
            }
        }
        else
        {
            getline(cin,str);
            if(str.substr(0,4)=="\\end") break; 
            if(str.substr(0,8)!="\\bibitem") continue;
            n=str.size();
            int pos=-1;
            for(int i=0;i<n;i++)
            {
                if(str[i]=='}')
                {
                    pos=i;
                    break;
                }
            }
            assert(pos!=-1&&pos>9);
            int len=pos-9;
            string tt=str.substr(9,len);
            ss[++cnt]=str;
            r[mp[tt]]=cnt;
        }
    }
    bool f=true;
    for(int i=1;i<=tot;i++) if(r[i]!=i) f=false;
    if(f) puts("Correct");
    else
    {
        puts("Incorrect");
        puts("\\begin{thebibliography}{99}");
        for(int i=1;i<=tot;i++) cout<<ss[r[i]]<<endl;
        puts("\\end{thebibliography}");
    }
    return 0;
}