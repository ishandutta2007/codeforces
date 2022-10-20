#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int a[2007][2007];

int main()
    {
    vector < pair < int , int > > v;
    int n;

    int i;
    int j;
    int x,y;
    pair < int , int > p;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&p.first,&p.second);
        p.first=p.first+1000;
        p.second=p.second+1000;
        v.push_back(p);
        a[p.first][p.second]=1;
        }
    int br=0;
    for(i=0;i<n-1;i++)
        {
        for(j=i+1;j<n;j++)
            {
            if(abs(v[i].first+v[j].first)%2==1)continue;
            if(abs(v[i].second+v[j].second)%2==1)continue;
            x=abs(v[i].first+v[j].first)/2;
            y=abs(v[i].second+v[j].second)/2;
            ///printf("%d %d \n",v[i].first,v[i].second);
            ///printf("%d %d \n",v[j].first,v[j].second);
            ///cout<<x<< " "<<y<<"\n";
            if(a[x][y]==1)br++;
            }
        }
    printf("%d\n",br);
    return 0;
    }