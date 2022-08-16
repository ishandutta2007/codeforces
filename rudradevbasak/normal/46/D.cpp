/*
Author : Continuum
Date   : 2010-09-24

*/


//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>


//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define ll                                  long long int
#define FOR(i,a,b)                          for(int i=a;i<b;i++)
#define REP(i,n)                            FOR(i,0,n)
#define pb                                  push_back
#define s(n)                                scanf("%d",&n)
#define sl(n)                               scanf("%lld",&n)
#define sf(n)                               scanf("%lf",&n)
#define fill(a,v)                           memset(a, v, sizeof a)
#define sz                                  size()
#define INF                                 int)1e9
#define EPS                                 1e-9
#define bitcount                            __builtin_popcount
#define all(x)                              x.begin(), x.end()
#define gcd                                 __gcd


/*Main code begins now */
int a[300000];

int beg[300000];
int end[300000];

int b,f,n;
int pos[1111];
int len[1111];

int read(int x,int ind)
{
    //printf("At %d with beg = %d , end = %d \n",ind,beg[ind],end[ind]);
    //if(x<0)
        //return 0;
    if(x==beg[ind] && x==end[ind])
        return a[ind];
    else if(x<=end[ind<<1])
        return a[ind]+read(x,ind<<1);
    else if(x>end[ind<<1])
        return a[ind]+read(x,(ind<<1)+1);
    else
        return a[ind]+read(x,ind<<1)+read(x,(ind<<1)+1);
}


void addto(int x,int y,int ind,int q)
{
    //printf("At %d with beg = %d , end = %d  , q = %d \n",ind,beg[ind],end[ind],q);
    if(y<x)
        return;
    if(x==beg[ind] && y==end[ind])
    {
        a[ind]+=q;
        //printf("At %d with beg = %d , end = %d  , q = %d \n",ind,beg[ind],end[ind],q);
    }
    else if(y<=end[ind<<1])
        addto(x,y,ind<<1,q);
    else if(x>end[ind<<1])
        addto(x,y,(ind<<1)+1,q);
    else
    {
        addto(x,end[ind<<1],ind<<1,q);
        addto(beg[(ind<<1)+1],y,(ind<<1)+1,q);
    }
        
}






void preprocess(int ind,int b,int e)
{
    beg[ind]=b;
    end[ind]=e;
    
    if(b!=e)
    {
        preprocess(ind<<1,b,(b+e)>>1);
        preprocess((ind<<1)+1,((b+e)>>1)+1,e);
    }
}




void input()
{
    int req;
    int i,j,k,curr,type,ind,z;
    s(n); s(b); s(f);
    s(req);
    fill(a,0);
    for(int i=0,j=0;i<req;i++,j++)
    {
        s(type);
        if(type==1)
        {
            
            s(len[j]);
            pos[j]=-1;
            curr=b;
            for(k=0;k<n+f;k++)
            {
                
                z=read(k,1);
                //printf("Read %d = %d \n",k,z);
                if(z==0)
                {
                    curr++;
                    if(curr==b+f+len[j])
                    {
                        pos[j]=k-f-len[j]+1;
                        printf("%d\n",pos[j]);
                        //printf("Adding %d \n",k);
                        addto(pos[j],pos[j]+len[j]-1,1,1);
                        //printf("Added %d \n",k);
                        break;
                    }
                }
                else
                    curr=0;
            }
            if(pos[j]==-1)
                printf("%d\n",pos[j]);
            
        }
        if(type==2)
        {
            s(ind);
            ind--;
            addto(pos[ind],pos[ind]+len[ind]-1,1,-1);
        }
            
    }
}


  
int main()
{

    preprocess(1,0,131071);

    int T=1; //s(T);
    while(T--)
    {
        input();
        //solve();
    }
        
}