#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


long long n,k;
long long a[100007];
set <long long> s;

void input();
void solve();



int main()
    {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%I64d%I64d",&n,&k);
    long long i;
    s.clear();
    for(i=0;i<n;i++)
        {
        scanf("%I64d",&a[i]);
        }
    }


void solve()
    {
    sort(a,a+n);
    int i;
    for(i=n-1;i>=0;i--)
        {
        if(s.count(k*a[i])==0)
            {
            s.insert(a[i]);
            }
        }
    cout<<s.size()<<"\n";
    }