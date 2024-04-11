#include<set>
#include<cstdio>

using namespace std;

int n,x,y,X[200020],Y[200020];
set<int>a[400040];
set<pair<int,int> >A;

void paint(int x)
{
    if(a[x].size())
    {
        int y=*(a[x].begin());
        a[x].erase(y);
        a[y].erase(x);
        A.insert(make_pair(x,y));
        paint(y);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        y=y+200000;
        a[x].insert(y);
        a[y].insert(x);
        X[i]=x;Y[i]=y;
    }
    for(int i=1;i<=400000;i++)if(a[i].size()&1)paint(i);
    for(int i=1;i<=400000;i++)while(a[i].size())paint(i);
    for(int i=1;i<=n;i++)
        if(A.find(make_pair(X[i],Y[i]))==A.end())putchar('r');
        else putchar('b');
}