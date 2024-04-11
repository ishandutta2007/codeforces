#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int n,k;
string a;

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
    scanf("%d%d",&n,&k);
    }


void solve()
    {
    int i;
    if(k>n || (k==1 && n!=1))
        {
        printf("-1\n");
        return ;
        }
    int left=n-k;
    left+=2;
    if(n==1)left=1;
    for(i=0;i<left;i++)
        {
        if(i%2==0)a+='a';
        else a+='b';
        }
    for(i=2;i<k;i++)
        {
        a+=(i+'a');
        }
    cout<<a<<"\n";
    }