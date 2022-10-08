#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
    set<int> a;int n;
    scanf("%d",&n);
    while(n--){int x;scanf("%d",&x),a.insert(x);}
    n=1;
    while(a.find(n)!=a.end())n++;
    printf("%d\n",n);
    return 0;
}