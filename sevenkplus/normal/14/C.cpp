#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define NaN 1000000001
int main()
{
    int x1,y1,x2,y2,x=0,y=0;
    map<pair<int,int>,int>a;
    a.clear();
    for(int i=0;i<4;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x+=(x1==x2&&y1!=y2),y+=(y1==y2&&x1!=x2);
        a[make_pair(x1,y1)]++,a[make_pair(x2,y2)]++;
    }
    bool f=(x==2&&y==2);
    for(map<pair<int,int>,int>::iterator I=a.begin();I!=a.end();f&=I->second==2,I++);
    puts(f?"YES":"NO");
    return 0;
}