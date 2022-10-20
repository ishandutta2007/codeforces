#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

int n;
string a;

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
    cin>>n;
    cin>>a;
    }

void solve()
    {
    int i;
    int s=-1;
    int t=-1;
    int metl=0;
    int metr=0;
    for(i=0;i<n;i++)
        {
        if(a[i]=='R' && s==-1)
            {
            s=i;
            metr=1;
            }
        if(a[i]=='L')
            {
            t=i-1;
            metl=1;
            break;
            }
        }
    if(metr==1 && metl==0)
        {
        int k;
        for(i=n-1;i>=0;i--)
            {
            if(a[i]=='R'){k=i;break;}
            }
        t=k+1;
        }
    if(metr==0 && metl==1)
        {
        int k;
        for(i=n-1;i>=0;i--)
            {
            if(a[i]=='L'){k=i;break;}
            }
        s=k;
        }
    cout<<s+1<<" "<<t+1<<"\n";
    }