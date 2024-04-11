#include<bits/stdc++.h>
#define MAXN 100
using namespace std;
char str[MAXN];
int n;
int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    int k=0;
    while(k<n)
    {
        int s=0;
        while(str[k]!='0'&&k<n)
        {
            k++;
            s++;
        }
        printf("%d",s);
        if(k<n) k++;
    }
    if(str[n-1]=='0') printf("0");
    return 0;
}