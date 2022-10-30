#include<iostream>
#include<cstdio>
#include<cstring>
#define N 105
using namespace std;
int n,a,now,num[N],tot,b[2];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a),num[a]++;
	for(int i=1;i<=100;i++)
    if(num[i]==(n>>1))
    b[tot++]=i;
    else if(num[i])
    {
        puts("NO");return 0;
    }
    printf("YES\n%d %d",b[0],b[1]);
}