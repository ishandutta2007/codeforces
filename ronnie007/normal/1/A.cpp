#include<iostream>
#include<stdio.h>
using namespace std;

long long n,m,a;


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
    cin>>n>>m>>a;
    }

void solve()
    {
    long long x,y;
    x=n/a;
    if(n%a!=0)x++;
    y=m/a;
    if(m%a!=0)y++;
    cout<<x*y<<"\n";
    }