#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;




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
    int i;
    int best=-1000000000;
    int n,k;
    int x,y;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&x,&y);
        if(y>k)
            {
            best=max(x-(y-k),best);
            }
        else
            {
            best=max(best,x);
            }
        }
    printf("%d\n",best);
    }


void solve()
    {

    }