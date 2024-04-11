#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
int main()
{
    int d,r,n,x,y,z;
    scanf("%d %d",&r,&d);
    scanf("%d",&n);
    int cnt=0;
    int lb=r-d,rb=r;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        double len=sqrt(x*x+y*y);
        if(len>=z&&len>=lb&&len+z<=rb&&len-z>=lb) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}