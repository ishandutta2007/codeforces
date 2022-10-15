#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
typedef long long ll;
int n;
int a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    ll s=0;
    for(int i=0;i<n;i++)
    {
        s+=a[i];
        if(s%2==1)
        {
            printf("First\n");
            return 0;
        }
    }
    printf("Second\n");
    return 0;
}