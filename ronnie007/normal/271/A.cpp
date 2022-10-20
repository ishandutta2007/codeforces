#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

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
    scanf("%d",&x);
    }


void solve()
    {
    int e,d,s,h;
    while(1)
        {
        x++;
        e=x%10;
        d=(x/10)%10;
        s=(x/100)%10;
        h=(x/1000)%10;
        if(e!=d && e!=s && e!=h && d!=s && d!=h && s!=h)
            {
            printf("%d\n",x);
            break;
            }
        }
    }