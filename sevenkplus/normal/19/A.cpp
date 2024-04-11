#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
struct T{int x,y,z;string w;T(string _w):x(0),y(0),z(0),w(_w){}T(){}};
map<string,T> a;
int n;
char s[1000];string t;
inline bool cmp(const T&a,const T&b)
{
    if(a.x!=b.x)return a.x>b.x;
    if(a.y!=b.y)return a.y>b.y;
    if(a.z!=b.z)return a.z>b.z;
}
string ss(char *s,int l,int r)
{
    string p;
    for(int i=l;i<r;i++)p.push_back(s[i]);
    return p;
}
int find(char *s){int p=1;for(;s[p]!='-';p++);return p;}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%s",s),t=ss(s,0,strlen(s)),a[t]=T(t);
    for(int i=0,x1,y1,p;i<n*(n-1)/2;i++)
    {
        scanf("%s %d:%d",s,&x1,&y1),p=find(s);
        string x=ss(s,0,p),y=ss(s,p+1,strlen(s));
        a[x].x+=(x1>y1?3:x1==y1?1:0),a[x].y+=x1-y1,a[x].z+=x1;
        a[y].x+=(x1<y1?3:x1==y1?1:0),a[y].y+=y1-x1,a[y].z+=y1;
    }
    vector<T> p;
    for(map<string,T>::iterator I=a.begin();I!=a.end();I++)p.push_back(I->second);
    sort(p.begin(),p.end(),cmp);
    vector<string> q;
    for(int i=0;i<n/2;i++)q.push_back(p[i].w);
    sort(q.begin(),q.end());
    for(vector<string>::iterator I=q.begin();I!=q.end();I++)cout<<*I<<endl;
    return 0;
}