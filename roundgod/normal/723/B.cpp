#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define MAXN 255
#define INF 100000000
using namespace std;
char str[MAXN];
int n,cnt,k,sav;
int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    sav=0;k=0;cnt=0;
    while(k<n)
    {
        if(str[k]=='(')
        {
            while(str[k]!=')')
            {
                k++;
                if((str[k]>='a'&&str[k]<='z')||(str[k]>='A'&&str[k]<='Z'))
                {
                    cnt++;
                    while ((str[k]>='a'&&str[k]<='z')||(str[k]>='A'&&str[k]<='Z')) k++;
                }
            }
        }
        else if((str[k]>='a'&&str[k]<='z')||(str[k]>='A'&&str[k]<='Z'))
        {
            int s=0;
             while ((str[k]>='a'&&str[k]<='z')||(str[k]>='A'&&str[k]<='Z')) {k++; s++;}
             sav=max(sav,s);
        }
        else k++;
    }
    printf("%d %d",sav,cnt);
    return 0;
}