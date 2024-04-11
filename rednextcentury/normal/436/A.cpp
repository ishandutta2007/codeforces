# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<ios>
using namespace std;
struct omnom
{
    int h;
    int m;
};
omnom a[100000];
omnom b[100000];
bool visited1[100000];
bool visited2[100000];
bool comp(omnom a,omnom b)
{
if (a.m==b.m)
return a.h>b.h;
    return a.m>b.m;
}
int main()
{   
    int n,x;
    cin>>n>>x;
    int numa=0,numb=0;
    for (int i=0;i<n;i++)
    {
        int t,h,m;
        cin>>t>>h>>m;
        if (t==0)
        {
            a[numa].m=m;
            a[numa++].h=h;
        }
        else
        {
            b[numb].h=h;
            b[numb++].m=m;
        }
    }
    sort(a,a+numa,comp);
    sort(b,b+numb,comp);
    int ans1=0;
    int x1=x;
    int loc_a=0;
    int loc_b=0;
    int turn=0;
    while(true)
    {
        if (turn==0 && loc_a==numa)
            break;
        else if (turn==1 && loc_b==numb)
            break;
        if (turn==0)
        {
            bool p=0;
            for (int i=0;i<numa;i++)
            {
                if (a[i].h<=x1 && !visited1[i])
                {
                     visited1[i]=1;
                    ans1++;
                    x1+=a[i].m;
                    p=1;
                    break;
                }
            }
            if (p==0)
                break;
        }
        else
        {
             bool p=0;
            for (int i=0;i<numb;i++)
            {
                if (b[i].h<=x1 && !visited2[i])
                {
                     visited2[i]=1;
                    ans1++;
                    x1+=b[i].m;
                    p=1;
                    break;
                }
            }
            if (p==0)
                break;
        }
        turn=1-turn;
    }
    int ans2=0;
    int x2=x;
    loc_a=0;
    loc_b=0;
    turn=1;
    memset(visited1,0,sizeof(visited1));
    memset(visited2,0,sizeof(visited2));
    while(true)
    {
        if (turn==0 && loc_a==numa)
            break;
        else if (turn==1 && loc_b==numb)
            break;
        if (turn==0)
        {
            bool p=0;
            for (int i=0;i<numa;i++)
            {
                if (a[i].h<=x2 && visited1[i]==0)
                {
                    visited1[i]=1;
                    ans2++;
                    x2+=a[i].m;
                    p=1;
                    break;
                }
            }
            if (p==0)
                break;
        }
        else
        {
            bool p=0;
            for (int i=0;i<numb;i++)
            {
                if (b[i].h<=x2 && visited2[i]==0)
                {
                    visited2[i]=1;
                    ans2++;
                    x2+=b[i].m;
                    p=1;
                    break;
                }
            }
            if (p==0)
                break;
        }
        turn=1-turn;
    }
    cout<<max(ans1,ans2)<<endl;
}