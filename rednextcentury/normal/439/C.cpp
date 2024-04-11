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
int even[100000];
int odd[100000];
queue<int> ev[100000];
queue<int> od[100000];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,k,p;
    cin>>n>>k>>p;
    int evens=0,odds=0;
    for (int i=0;i<n;i++)
    {
        int o;
        cin>>o;
        if (o%2==0)
            even[evens++]=o;
        else
            odd[odds++]=o;
    }
    if ( (odds<k-p) || (evens<p && (odds-(k-p))/2<p-evens))
    {
        cout<<"NO\n";
    }
    else
    {
        for (int i=0;i<k-p;i++)
        {
            if (odds>0)
            {
            od[i].push(odd[odds-1]);
            odds--;
            }
            else
            {
                cout<<"NO\n";
                return 0;
            }
        }
        for (int i=0;i<p;i++)
        {
            if (evens>0)
            {
                ev[i].push(even[evens-1]);
                evens--;
            }
            else
            {
                if (odds<2)
                {
                    cout<<"NO\n";
                    return 0;
                }
                ev[i].push(odd[odds-1]);
                ev[i].push(odd[odds-2]);
                odds-=2;
            }
        }
        if (p==0)
        {
            while(evens>0)
            {
                evens--;
                od[0].push(even[evens]);
            }
        }
        else
        {
            while(evens>0)
            {
                evens--;
                ev[0].push(even[evens]);
            }
        }
        if (odds%2!=0)
        {
            cout<<"NO\n";
            return 0;
        }
        if (k==p)
        {
            while(odds>0)
            {
                ev[0].push(odd[odds-1]);
                odds--;
            }
        }
        else
        {
            while(odds>0)
            {
                od[0].push(odd[odds-1]);
                odds--;
            }
        }
        
        cout<<"YES\n";
        for (int i=0;i<p;i++)
        {
            int j=ev[i].size();
            cout<<j;
            for (int x=0;x<j;x++)
            {
                cout<<" "<<ev[i].front();
                ev[i].pop();
            }
            cout<<"\n";
        }
        for (int i=0;i<k-p;i++)
        {
            int j=od[i].size();
            cout<<j;
            for (int x=0;x<j;x++)
            {
                cout<<" "<<od[i].front();
                od[i].pop();
            }
            cout<<"\n";
        }
    }
}