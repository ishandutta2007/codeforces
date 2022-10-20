#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;



string a;
int n;
int br[15];
int br1;
int used[15];
long long ans;

void input();
void solve();


int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    cin>>a;
    n=a.size();
    int i;
    for(i=0;i<n;i++)
        {
        if(a[i]<'A' || a[i]>'J')continue;
        br[a[i]-'A']++;
        }
    }

void solve()
    {
    int i;
    for(i=0;i<=9;i++)
        {
        if(br[i]!=0)br1++;
        }
    int x;
    ans=1;
    int k=0;
    for(i=0;i<n;i++)
        {
        if(a[i]<'A' || a[i]>'J')continue;
        x=a[i]-'A';
        if(used[x]==0)
            {
            if(i==0)ans=ans*(9-k);
            else ans=ans*(10-k);
            k++;
            used[x]=1;
            }
        }
    if(a[0]=='?')ans=ans*9;
    printf("%I64d",ans);
    for(i=1;i<n;i++)
        {
        if(a[i]=='?')printf("0");
        }
    printf("\n");
    }