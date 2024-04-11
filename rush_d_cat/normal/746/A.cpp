#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int NICO = 1005;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int maxc = 0;
    for(int i=1;i<=1000;i++)
    {
        if(i<=a && 2*i <= b && 4*i <= c)
        {
            maxc = 7*i;
        }
    }   
    cout << maxc << endl;
}