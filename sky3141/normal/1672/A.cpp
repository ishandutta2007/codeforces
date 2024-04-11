#include <iostream>
using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n, cnt = 0;
        scanf("%d", &n);
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d", &x);
            cnt += x - 1;
        }
        if(cnt % 2) puts("errorgorn");
        else puts("maomao90");
    }
    return 0;
}