#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


const long long tbl[]={127,32767,2147483647,9223372036854775807LL};
const char name[][20]={"byte","short","int","long","BigInteger"};


int main()
    {
    long double n;
    int i;
    cin >> n;
    for ( i = 0; i < 4; i++ )
        {
        if ( n <= tbl[i] ) break;
        }
    cout << name[i] << "\n";
    return 0;
    }