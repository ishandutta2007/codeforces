#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN];
int cnt0,cnt1,cnt2;
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    cnt0=cnt1=cnt2=0;
    for(int i=1;i<=n;i++) if(str[i]=='0') cnt0++; else if(str[i]=='1') cnt1++; else cnt2++;
    if(cnt0<n/3)
    {
        for(int i=1;i<=n;i++) 
        {
            if(cnt0==n/3) break;
            if(str[i]=='1'&&cnt1>n/3)
            {
                str[i]='0';
                cnt1--;cnt0++;
            }
            if(str[i]=='2'&&cnt2>n/3)
            {
                str[i]='0';
                cnt2--;cnt0++;
            }
        }
    }
    if(cnt0>n/3)
    {
        for(int i=n;i>=1;i--)
        {
            if(str[i]=='0'&&cnt0>n/3)
            {
                if(cnt2<n/3) {str[i]='2'; cnt0--; cnt2++;}
                else if(cnt1<n/3) {str[i]='1'; cnt0--; cnt1++;}
            }
        }
    }
    if(cnt1<n/3)
    {
        for(int i=1;i<=n;i++) 
        {
            if(cnt1==n/3) break;
            if(str[i]=='2'&&cnt2>n/3)
            {
                str[i]='1';
                cnt2--;cnt1++;
            }
        }
    }
    if(cnt1>n/3)
    {
        for(int i=n;i>=1;i--) 
        {
            if(cnt1==n/3) break;
            if(str[i]=='1'&&cnt2<n/3)
            {
                str[i]='2';
                cnt2++;cnt1--;
            }
        }
    }
    printf("%s\n",str+1);
    return 0;
}