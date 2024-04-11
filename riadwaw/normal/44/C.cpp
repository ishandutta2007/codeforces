#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
using namespace std;
int main(){
    //freopen("input.txt","r",stdin);
    int n,m,q,w;
    int a[101];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        a[i]=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&q,&w);
        for(int j=q-1;j<w;j++)
            a[j]++;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=1)
        {
            printf("%d %d",i+1,a[i]);
            return 0;
        }
    }
    printf("OK");
    return 0;
}