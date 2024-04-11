#include <iostream>
#include <math.h>

using namespace std;

int N;

int main()
{
    int p[2], a=0;
    cin >> N;
    for(int i = 0;i < N;i++)
    {
        cin >> p[0] >> p[1];
        if (p[1] - p[0] >= 2) 
            a++;
    }
    cout << a << endl;
}