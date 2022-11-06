#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 10020

using namespace std;
typedef long long int ll;

char s[maxn],s1[maxn];
int n,l,r,t;

int main()
{
    scanf("%s",s);
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d%d",&l,&r,&n);l--;r--;
        n=n%(r-l+1); 
        for (int i=0;i<n;i++) s1[n-i-1]=s[r-i];
        for (int i=r;i>=l+n;i--) s[i]=s[i-n];
        for (int i=l;i<l+n;i++) s[i]=s1[i-l];
    }
    printf("%s\n",s);
    return 0;
}