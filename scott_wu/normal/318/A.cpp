#include <iostream> //scott
#include<cstdio>

using namespace std;

int main()
{
    __int64 n,k;
    cin >> n >> k;
    if (k>(n+1)/2)
        cout << 2 * (k - (n+1)/2);
        else cout<< k*2-1; 
    return 0;
}