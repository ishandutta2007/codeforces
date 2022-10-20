#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int main()
    {
    long long n,d,nd=0,sg=0,o,p=1,l;
    cin>>n>>d;
    sg=n;
    while(n-sg<=d)
        {
        l=0;
        o=sg;
        nd*=10;
        nd+=9;
        p*=10;
        if((sg/(p/10)%10)==9)l=1;
        sg=sg/p;
        sg*=p;
        if(l==0)sg-=p;
        sg+=nd;
        }
    cout<<o<<endl;
    }