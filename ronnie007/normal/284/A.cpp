#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

int p;
int x;


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
    scanf("%d",&p);
    }


void solve()
    {
    int i;
    int j;
    int ans=0;
    int fl=0;
    int num=1;
    int g;
    for(i=1;i<p;i++)
        {
        fl=0;
        num=1;
        g=i;
        for(j=1;j<=p-1;j++)
            {
            num=num*g;
            num=num%p;
            if(num==1 && j!=p-1){fl=1;break;}
            if(num==1)break;
            //cout<<num<<" ";
            }
        //cout<<"\n";
        if(fl==0 && num==1)ans++;
        }
    printf("%d\n",ans);
    }