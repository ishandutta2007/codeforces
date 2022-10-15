#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
char str[200];
int main()
{
    scanf("%d %d\n",&n,&m);
    int f=1;
    for(int i=0;i<n;i++)
    {
        gets(str);
        if(!f) break;
        for(int j=0;j<m;j++)
        {
            if(str[j*2]=='C'||str[j*2]=='Y'||str[j*2]=='M')
            {
                f=0;
                break;
            }
        }
    }
    if(f) printf("#Black&White\n"); else printf("#Color\n");
    return 0;
}