#include<cstdio>
#include<algorithm>

using namespace std;

int x,y;

int main()
{
    scanf("%d%d",&x,&y);
    if(min(x,y)%2)puts("Akshat");
    else puts("Malvika");
}