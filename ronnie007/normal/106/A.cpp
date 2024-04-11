#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long Int;

int main()
{
    char rank1,rank2,suit1,suit2;
    char trump;
    Int r1,r2;
    
    cin>>trump;
    cin>>rank1>>suit1>>rank2>>suit2;
    
    if (rank1=='A')
    r1=14;
    else if (rank1=='K')
    r1=13;
    else if (rank1=='Q')
    r1=12;
    else if (rank1=='J')
    r1=11;
    else if (rank1=='T')
    r1=10;
    else
    r1=rank1-'0';
    
    
    if (rank2=='A')
    r2=14;
    else if (rank2=='K')
    r2=13;
    else if (rank2=='Q')
    r2=12;
    else if (rank2=='J')
    r2=11;
    else if (rank2=='T')
    r2=10;
    else
    r2=rank2-'0';
    
    if (suit1==suit2)
    {
        if (r1>r2)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    else
    {
        if (suit1==trump)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}