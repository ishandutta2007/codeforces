#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


int n,k;
int a[200007];
int used[200007];
int br=0;
void input();
void solve();


int main()
    {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;i++)
        {
        scanf("%d",&a[i]);
        }
    int l,r;
    for(i=0;i<k;i++)
        {
        scanf("%d%d",&l,&r);
        used[l-1]++;
        used[r]--;
        }
    }


void solve()
    {
    int i;
    br=used[0];
    int h;
    for(i=1;i<=n;i++)
        {
        h=used[i];
        used[i]=br;
        br+=h;
        }
    sort(used+1,used+1+n);
    sort(a+1,a+1+n);
    long long ans=0;
    int j=n;
    for(i=n;i>=1;i--)
        {
        if(used[i]!=0)
            {
            //cout<<used[i]<<"\n";
            ans+=(long long)used[i]*a[j];
            j--;
            }
        else break;
        }
    printf("%I64d\n",ans);
    }