#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int av[1000];
int main()
{
    for (int i=0;i<6;i++)
    {
        int h;
        cin>>h;
        av[h]++;
    }
    int tot=0;
    int l[100]={0};
    for (int i=0;i<10;i++)
    {
        if (av[i]>0)
            l[tot++]=av[i];
    }
    sort(l,l+tot);
    if ((tot==2 && l[0]==2 && l[1]==4) ||(tot==1 && l[0]==6))
        cout<<"Elephant"<<endl;
    else if ((tot==3 && l[0]==1 && l[1]==1 && l[2]==4) || (tot==2 && l[0]==1 && l[1]==5))
        cout<<"Bear"<<endl;
    else
        cout<<"Alien"<<endl;
}