#include<cstdio>
using namespace std;

int main()
{
    puts("2000");
    for (int i=1;i<=1000;i++) printf("%d %d %d %d\n",i,1,i,2);
    for (int i=1000;i>=1;i--) printf("%d %d %d %d\n",i,1,i,2);
}