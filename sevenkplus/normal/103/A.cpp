#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll S=0;int n;
int main()
{
    scanf("%d",&n);
    for(int i=0,x;i<n;i++)
    {
        scanf("%d",&x);
        S+=(ll)i*(x-1)+x;
    }
    printf("%I64d\n",S);
    return 0;
}