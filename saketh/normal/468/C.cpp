#include <iostream>
#include <stdio.h>
using namespace std;

unsigned long long a;

int main(){
    cin >> a;

    unsigned long long s = 45 * 19;
    for(int i=0; i<18; i++)
        s = (s * 10) % a;

    s = (s + 1) % a;
    s = (a - s) % a;

    printf("%lld 1%019lld\n", s+1, s);
    return 0;
}