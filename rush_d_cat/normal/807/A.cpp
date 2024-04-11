#include <iostream>
using namespace std;
int n, a[1002], b[1002];
int main()
{
    scanf("%d", &n);
    int sam = 1, dc = 1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d", &a[i], &b[i]);
        if(a[i] != b[i])
        {
            sam = 0;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i] > a[i-1])
        {
            dc = 0;
        }
    }
    if(!sam)
    {
        printf("rated\n");
    } else if(dc) {
        printf("maybe\n");
    } else {
        printf("unrated\n");
    }
}