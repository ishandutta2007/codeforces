# include<iostream>
#include<bits/stdc++.h>
#define EPS 1e-6
#include <stdio.h>
using namespace std;
multiset<long long> st;
pair<long long,long long> d1[1000000];
long long d2[1000000];
int col( int x1,int y1,int x2,int y2,int x3,int y3)
{
    int s=0;
    if (x1==x2 || y1==y2)
        s++;
    if (x1==x3 || y1==y3)
        s++;
    if (x2==x3 || y2==y3)
        s++;
    if (s==0)
        return 3;
    else if (s==1)
    {
        pair<int,int> p[3];
        p[0]=make_pair(y1,x1),p[1]=make_pair(y2,x2),p[2]=make_pair(y3,x3);
        sort(p,p+3);
        if (p[0].second==p[1].second || p[1].second==p[2].second)
            return 2;
        swap(p[0].first,p[0].second);
        swap(p[1].first,p[1].second);
        swap(p[2].first,p[2].second);
        sort(p,p+3);
        if (p[0].second==p[1].second || p[1].second==p[2].second)
            return 2;
        return 3;
    }
    else if (s==2)
        return 2;
    else
        return 1;
}
int main()
{
    int x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    cout<<col(x1,y1,x2,y2,x3,y3)<<endl;

}