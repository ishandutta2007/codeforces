#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, numNines, sumthing, total = 0, t;
    cin >> n;
    numNines = log10(2*n);
    for(int i = 1; i < 10; i++)
    {
        sumthing = pow(10, numNines)*i - 1;
        t = min((sumthing - 1)/2, n) - max(0, (sumthing - n - 1));
        if(t > 0) total += t;
    }
    if(n < 5)
    {
        if(n == 2) cout << 1;
        if(n == 3) cout << 3;
        if(n == 4) cout << 6;
    }
    else
    {
        cout << total;
    }
}