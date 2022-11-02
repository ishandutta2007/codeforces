#include<iostream>
#include<cstdio>
#include<cstring>
#define V 43200
using namespace std;
int n,h,m,s,t1,t2;
bool mp[V],f;
int main()
{
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
	h=(h*3600+m*60+s)%V,m=(m*720+s*12)%V,s=(s*720)%V;
	t1=t1*3600%V,t2=t2*3600%V;
	mp[h]=mp[m]=mp[s]=1;
	for(int i=t1;i!=t2;i=(i+1)%V)
    if(mp[i]){f=1;break;}
    if(!f){puts("YES");return 0;}
    for(int i=t1;i!=t2;i=(i+V-1)%V)
    if(mp[i]){f=0;break;}
    puts(f?"YES":"NO");
}