#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;


int n,m;

struct tuhla
    {
    int balls;
    int pos;
    };


bool operator <(struct tuhla x1,struct tuhla x2)
    {
    if(x1.balls<x2.balls)return false;
    if(x2.balls<x1.balls)return true;
    int close1;
    int close2;
    close1=abs((m+1)/2-x1.pos);
    close2=abs((m+1)/2-x2.pos);
    if(m%2==0 && x2.pos>x1.pos)close2--;
    if(m%2==0 && x1.pos>x2.pos)close1--;
    if(close1<close2)return false;
    if(close1>close2)return true;
    if(x1.pos<=x2.pos)return false;
    return true;
    }


priority_queue < struct tuhla > q;


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
    scanf("%d%d",&n,&m);
    }



void solve()
    {
    struct tuhla p;
    int i;
    while(q.empty()==false)q.pop();
    for(i=1;i<=m;i++)
        {
        p.balls=0;
        p.pos=i;
        q.push(p);
        }
    for(i=1;i<=n;i++)
        {
        p=q.top();
        q.pop();
        printf("%d\n",p.pos);
        p.balls++;
        q.push(p);
        }

    }