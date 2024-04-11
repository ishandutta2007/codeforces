#include<cstdio>
#include<map>
std::map<int,int> A;
int main()
{
    int S=0,n;
    scanf("%d",&n);
    for(int i=0,x;i<n;i++)
        scanf("%d",&x),A[S+=x]++;
    printf("%d\n",S==0?A[0]-1:S&1?0:A[S/2]);
    return 0;
}