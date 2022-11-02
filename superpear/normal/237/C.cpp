#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

const int maxn=1000000;

int prime[maxn+10],sum[maxn+10];
int a,b,k,flag;

int main()
{
    memset(prime,0,sizeof(prime));
    prime[1]=1;
    for (int i=2;i<=maxn;i++)
        if (prime[i]==0)
        {
            for (int j=i*2;j<=maxn;j+=i)
                prime[j]=1;
        }
    sum[0]=0;
    for (int i=1;i<=maxn;i++) sum[i]=sum[i-1]+1-prime[i];
    scanf("%d %d %d",&a,&b,&k);
    int left,right,mid;
    left=1;right=b-a+1;
    while (left<=right)
    {
        mid=(left+right)/2;
        flag=1;
        for (int i=a;i<=b-mid+1;i++)
            if (sum[i+mid-1]-sum[i-1]<k)
            {
                flag=0;break;
            }
        if (flag==1) right=mid-1; else left=mid+1;
    }
    if (left>b-a+1) left=-1;
    cout<<left<<endl;

    return 0;
}