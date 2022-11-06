#include <iostream>
using namespace std;

int main()
{
    int p1, p2, p3, p4, a, b;
    cin>>p1>>p2>>p3>>p4>>a>>b;
    int cnt = 0;
    for(int i=a;i<=b;i++)
        if((((i % p1) % p2) % p3) % p4 == i)
            ++cnt;
    cout<<cnt<<endl;
    return 0;
}/////////////