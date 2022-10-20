#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

void input();
void solve();

string a;

int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    cin >> a;
    }
void solve()
    {
    int i;
    for ( i = 0 ; i < a.size(); i++)
        {
        if ( a[ i ] != '1' && a[ i ] !='4' ){printf("NO\n");return ;}
        }
    for ( i = 0 ; i < a.size(); i++)
        {
        if ( a[ i ] == '1'){break;}
        }

    if ( i == a.size()){printf("NO\n");return ;}
    int br=1;
    for ( i = 1 ; i < a.size(); i ++ )
        {
        if ( a[ i ] == a[ i - 1 ] && a[ i ] =='4' ) br ++;
        else
            {
            if ( br > 2 )
                {
                printf("NO\n");
                return ;
                }
            br = 1;
            }
        }
    if ( br > 2 )
        {
        printf("NO\n");
        return ;
        }
    if ( a[ 0 ] !='1'){printf("NO\n");return ;}
    printf("YES\n");
    }