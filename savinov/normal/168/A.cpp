#include <iostream>

using namespace std;

int main()
{
    int n,x,y;
    cin >> n >> x >> y;
    int i = 0;
    while (100*(x+i)<n*y) i++;
    cout << i;
    return 0;
}