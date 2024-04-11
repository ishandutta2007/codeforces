#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


long long n;
int t;

void input();
long long nod(long long a,long long b);

int main()
    {
    input();
    return 0;
    }
    
    
void input()
    {
    cin>>t;
    int i;
    long long nd;
    long long LCM;
    for(i=0;i<t;i++)
        {
        cin>>n;
        nd=nod(4*n,n+1);
        LCM=((4*n)/nd)*(n+1);
        cout<<(LCM/(n+1))+1<<"\n";
        }
    }
    
long long nod(long long a,long long b)
    {
    if(b==0)return a;
    return nod(b,a%b);
    }