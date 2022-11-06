#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;

bool prime(int x)
{
	for (int i=2;i*i<=x;i++)
	    if (x%i==0) return false;
	return true;
}

int main()
{
	scanf("%d",&n);
	if (n<9) {
		printf("1\n%d\n",n);
		return 0;
	}
	n-=3;
    m=3;
    while ((!prime(m))||(!prime(n-m))) m+=2;
    printf("3\n3 %d %d\n",m,n-m);
    return 0;
}