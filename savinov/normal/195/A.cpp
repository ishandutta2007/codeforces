#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int i=0;
    while (1)
    {
        if ((a*c-b*i)<=c*b)
        {
            cout << i << endl;
            return 0;
        }
        i++;
    }
    return 0;
}