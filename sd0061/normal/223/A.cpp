#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 100005
int n ;
char s[N];
int mat[N],stk[N],top,sum[N];


void work()
{
    memset(mat,-1,sizeof(mat));
    int n=strlen(gets(s));
    for ( int i=0; i<n; i++ )
    {
        if ( s[i]=='(' || s[i]=='[' )
          stk[top++]=i;
        else if ( s[i]==')' )
        {
            if ( top>0 && s[stk[top-1]]=='(' )
              mat[i]=stk[--top];
            else top=0;
        }
        else if ( s[i]==']' )
        {
            if ( top>0 && s[stk[top-1]]=='[' )
              mat[i]=stk[--top];
            else top=0;
        }
    }
    for ( int i=0; i<n; i++ )
      if ( mat[i]>0 && mat[mat[i]-1]!=-1 )
        mat[i]=mat[mat[i]-1];
    for ( int i=0; i<n; i++ ) sum[i+1]=sum[i]+(s[i]=='[');
    int big=-1,st=0,ed=0;
    for ( int i=0; i<n; i++ ) if ( mat[i]!=-1 )
     {
        int l=mat[i],r=i,now=sum[r+1]-sum[l];
        if ( now>big ) {
            big=now;
            st=l; ed=r;
        }
    }
    if ( big==-1 ) {
        puts("0\n");
        return;
    }
    printf("%d\n",big);
    for ( int i=st; i<=ed; i++ ) putchar(s[i]);
}

int main()
{
  work();
  return 0;
}