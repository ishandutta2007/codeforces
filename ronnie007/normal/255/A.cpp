#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int x;
int i;
int n;
int br1=0;
int br2=0;
int br3=0;

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
    int i;
    for(i=0;i<n;i++)
        {
        scanf("%d",&x);
        if(i%3==0)br1+=x;
        if(i%3==1)br2+=x;
        if(i%3==2)br3+=x;
        }
    }


void solve()
    {
    //printf("%d %d %d\n",br1,br2,br3);
    int mx=max(max(br1,br2),br3);
    if(mx==br1)printf("chest\n");
    if(mx==br2)printf("biceps\n");
    if(mx==br3)printf("back\n");
    }