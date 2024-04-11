#include<set>
#include<cstdio>
#include<algorithm>

using namespace std;

set<int>a;

int n,o,Max;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&o);
        while(a.find(o)!=a.end())
            a.erase(o),o++;
        a.insert(o);
        Max=max(Max,o);
    }
    printf("%d\n",Max-a.size()+1);
}