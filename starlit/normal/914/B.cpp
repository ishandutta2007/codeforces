#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,a,t[N];
int main()
{
	scanf("%d",&n);
	while(n--)
    {
        scanf("%d",&a);
        t[a]++;
    }
    for(int i=1;i<=100000;i++)
    if(t[i]&1)
    return puts("Conan"),0;
    puts("Agasa");
}