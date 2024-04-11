#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;



int n;
int a,b,c;



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
    scanf("%d",&n);
    }

void solve()
    {
    double lft;
    double ans;
    int p;
    long long br=0;
    for(c=n;c>=1;c--)
        {
        for(a=1;a*a<=c*c/2;a++)
            {
            p=c*c-a*a;
            ans=sqrt(p);
            if(int(ans)*int(ans)==p)br++;
            }
        }
    printf("%I64d\n",br);
    }