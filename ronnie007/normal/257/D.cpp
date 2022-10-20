#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

string ans;
int n;
int a[100007];


void input();


int main()
    {
    input();
    return 0;
    }
    
    
void input()
    {
    scanf("%d",&n);
    int i;
    int sum;
    for(i=1;i<=n;i++)
        {
        scanf("%d",&a[i]);
        }
    sum=a[n];
    ans+='+';
    for(i=n-1;i>=1;i--)
        {
        if(sum>=0)
            {
            sum-=a[i];
            ans+='-';
            }
        else
            {
            sum+=a[i];
            ans+='+';
            }
        }
    int sz=ans.size();
    if(sum>=0)
        {
        for(i=sz-1;i>=0;i--)
            {
            cout<<ans[i];
            }
        }
    else
        {
        for(i=sz-1;i>=0;i--)
            {
            if(ans[i]=='+')cout<<"-";
            else cout<<"+";
            }
        }
    cout<<"\n";
    }