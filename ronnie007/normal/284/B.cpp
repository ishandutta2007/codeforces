#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
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
    int brin=0;
    int i;
    int brf=0;
    int bra=0;
    for(i=0;i<n;i++)
        {
        if(a[i]=='F')brf++;
        if(a[i]=='I')brin++;
        if(a[i]=='A')bra++;
        }
    if(brin==0)
        {
        printf("%d\n",bra);
        }
    else
        {
        if(brin==1)printf("1\n");
        else printf("0\n");
        }
    }