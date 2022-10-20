#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;


long long ans;
long long w,h;



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
    scanf("%I64d%I64d",&w,&h);
    }



void solve()
    {
    long long i,j;
    long long l,r;
    for(i=1;i<h;i++)
        {
        for(j=1;j<=w;j++)
            {
            l=0;
            r=i+(i-l);
            if(r>h)
                {
                l+=(r-h);
                r=h;
                }
            //cout<<r<<" "<<l<<"\n";
            //cout<<(w-j+1)*(i-l)<<"\n";
            if(l<i && j%2==0){ans+=(w-j+1)*(i-l);}
            }
        }
    printf("%I64d\n",ans);
    }