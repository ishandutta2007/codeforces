#include <iostream>
using namespace std;
int main()
{
    int k;cin >> k;
    int x = 1;
    while(x*(x+1)/2 <= k) x++;
    cout << (x-1) << endl;
    for(int i=1;i<=x-2;i++) cout << i << " ";
    cout << (k - (x-1)*(x-2)/2) << endl;
}