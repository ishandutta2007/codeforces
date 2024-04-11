#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
int s,v1,v2,t1,t2;
int main()
{
    scanf("%d %d %d %d %d",&s,&v1,&v2,&t1,&t2);
    int x=v1*s+2*t1,y=v2*s+2*t2;
    if(x<y) printf("First\n");
    if(x>y) printf("Second\n");
    if(x==y) printf("Friendship\n");
    return 0;
}