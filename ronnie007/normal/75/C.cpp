#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector <long long> CD;


void getCDs(long long x,long long y)
    {
    long long i;
    for(i=1;i*i<=x;i++)
        {
        if(x%i==0)
            {
            if(y%i==0)
                {
                CD.push_back(i);
                }
            if(y%(x/i)==0 && i*i!=x)
                {
                CD.push_back(x/i);
                }
            }
        }
    }




int main()
    {
    long long a,b;
    long long r,l;
    int i,j;
    int n;
    int mid;
    scanf("%I64d%I64d",&a,&b);
    getCDs(a,b);
    scanf("%d",&n);
    int sz=CD.size();
    int ind=-1;
    sort(CD.begin(),CD.end());
    for(i=0;i<n;i++)
        {
        scanf("%I64d%I64d",&l,&r);
        ind=-1;
        for(j=sz;j>=0;j--)
            {
            if(CD[j]>=l && CD[j]<=r){ind=j;break;}
            }
        if(ind==-1)printf("-1\n");
        else printf("%I64d\n",CD[ind]);
        }
    return 0;
    }