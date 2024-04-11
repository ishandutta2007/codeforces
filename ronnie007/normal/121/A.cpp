#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

vector < long long > v;

void gen()
    {
    int i,j;
    v.clear();
    v.push_back(0);
    int br = 1;
    int sz = 1;
    for ( i = 1; i <= 10 ; i ++ )
        {
        sz = v.size();
        for ( j = sz - 1 ; j >= sz-br ; j -- )
            {
            v.push_back ( v[ j ]* 10 + 4);
            v.push_back ( v[ j ]* 10 + 7);
            }
        br = br * 2;
        }
    sort(v.begin(),v.end());
    }


long long f ( long long x )
    {
    int i;
    int n = v.size();
    long long ans = 0;
    for ( i = 1 ; i < n ; i ++ )
        {
        ///cout << ans << " \n ";
        if ( v[ i ] <= x ) ans = ans + v[ i ] * ( v[ i ] - v[ i - 1 ] );
        else
            {
            ans = ans + v[ i ] * ( x - v[ i - 1 ] );
            break ;
            }
        }
    return ans;
    }


int main()
    {
    gen();
    long long x,y;
    scanf("%I64d%I64d",&x,&y);
    ///printf("%I64d\n",f(x-1));
    ///printf("%I64d\n",f(y));
    printf("%I64d\n",f(y)-f(x-1));
    return 0;
    }