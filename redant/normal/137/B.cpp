#include <cstdio>
#include <cstring>
using namespace std;

int f[5005], n;

int main()
{
    scanf("%d",&n);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x<1 || x>n || f[x]) ans++;
        if(x>=1 && x<=n) f[x] = 1;
    }
    printf("%d\n",ans);
    return 0;
}