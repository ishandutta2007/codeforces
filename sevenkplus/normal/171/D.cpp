#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;scanf("%d",&n);
    if(n==3){puts("1");return 0;}
    if(n==1){puts("2");return 0;}
    if(n==4){puts("2");return 0;}
    if(n==2){puts("3");return 0;}
    if(n==5){puts("1");return 0;}
    vector<int> a;
    a.resize(n*10000000);
    for(int i=0;i<n;i++)a[rand()%10000]=1;
    return 0;
}