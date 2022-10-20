#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

long long p[17];

vector < long long > v;

int find ( int n )
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
            v.push_back ( v[ j ] * 10 + 4);
            v.push_back ( v[ j ] * 10 + 7);
            }
        br = br * 2;
        }

    sort(v.begin(),v.end());
    int ans = 0;
    for ( i = 1 ; i < v.size() ; i ++ )
        {
        if ( v[ i ] <= n )
            {
            ///printf( " %d\n",v[ i ] );
            ans ++;
            }
        else break;
        }
    return ans;
    }

bool islucky ( int x )
    {
    int t;
    while ( x != 0 )
        {
        t = x%10;
        x = x/10;
        if( t != 4 && t != 7 ) return false;
        }
    return true;
    }

int main()
    {
    int n,k;
    p[ 0 ] = 1;
    p[ 1 ] = 1;
    for (int i = 2 ;i < 13 ; i ++ ) p [ i ] = i * ( p [ i - 1 ] ) ;

    scanf ( "%d%d" , &n , &k );
    if ( n < 13 && p [ n ] < k )
        {
        printf ( "-1\n");
        return 0;
        }
    int ans = 0;

    if ( n > 13 ) ans = find ( n - 13 ) ;
    int left = min ( n , 13 ) ;

    ///cout << ans << " \n ";
    bool used[17];
    int perm[17];

    for (int i = 0; i < left; i++) used[i] = false;

    for (int i = 0, m = k - 1, l = left; l > 0; i++, l--)
        {
        int d = m / p[left - i - 1];

        int j = -1;
        for (int q = 0; q < d + 1; q++)
            {
            j++;
            while (used[j]) j++;
            }
        perm[i] = n - left + 1 + j;
        used[j] = true;

        m %= p[left - i - 1];
        }


    for (int i = 0; i < left; i++)
        {
        if (islucky(n - left + 1 + i) && islucky(perm[i])) ans++;
        }

    printf("%d\n", ans);
    return 0;
    }