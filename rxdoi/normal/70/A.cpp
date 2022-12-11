#include<cstdio>
using namespace std;

const int Mod=1e6+3;
int n;

inline int calc(int n)
{
    if (n<=1) return 1;
    return 3*calc(n-1)%Mod;
}

int main()
{
    scanf("%d",&n);
    printf("%d\n",calc(n));
}