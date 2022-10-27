#include<iostream>
using namespace std;
typedef __int64 ll;
int n,m;
int main()
{
    cin>>n>>m;
    if(n==1) printf("1\n");
    else if(n-m>m-1) printf("%d\n",m+1);
    else printf("%d\n",m-1);
    return 0;
}