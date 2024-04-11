#include<bits/stdc++.h>
using namespace std;
int t,f,i,j,p,q,x,y,dx[128],dy[128];
char s[5008];
int main() {
    for(dx['L']=-(dx['R']=1),dy['D']=-(dy['U']=1),scanf("%d",&t);
            t--; f?0:printf("0 0\n"))
        for(scanf("%s",s),f=i=p=q=0; s[i]; x||y?++i:
                (printf("%d %d\n",p,q),f=i=strlen(s)))
            for(p+=dx[s[i]],q+=dy[s[j=i]],j=x=y=0; s[j]; x+=dx[s[j]],
                    y+=dy[s[j]],x==p&&y==q?(x-=dx[s[j]],y-=dy[s[j]]):0,++j);
    exit(0);
}