#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;



long long n;
vector <long long > v;
vector <long long > numbers;
long long m;
long long br1=0;
void input();
void solve();
bool f(struct point p1,struct point p2);

int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%I64d",&n);
    int i;
    long long x;
    v.clear();
    for(i=0;i<n;i++)
        {
        scanf("%I64d",&x);
        v.push_back(x);
        }
    for(i=n;i<n+n;i++)
        {
        scanf("%I64d",&x);
        if(x==v[i-n])br1++;
        v.push_back(x);
        }
    scanf("%I64d",&m);
    sort(v.begin(),v.end());
    }


void solve()
    {
    long long i,j;
    long long ans=1;
    long long br=1;
    unsigned long long k;
    numbers.clear();
    for(i=1;i<2*n;i++)
        {
        if(v[i]==v[i-1])
            {
            br++;
            }
        else
            {
            if(br>1)numbers.push_back(br);
            br=1;
            }
        //cout<<ans<<"\n";
        }
    if(br!=1)numbers.push_back(br);
    //cout<<br<<"\n";
    //ans=(ans*br);
    for(i=0;i<numbers.size();i++)
        {
        k=1;
        for(j=2;j<=numbers[i];j++)
            {
            k=j;
            while(br1>0 && k%2==0)
                {
                br1--;
                k=k/2;
                }
            ans=(ans*k)%m;
            }
        }
    printf("%I64d\n",ans);
    }