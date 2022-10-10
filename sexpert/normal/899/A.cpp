#include <iostream>

using namespace std;

int main()
{
    int n, k, s = 0, ones = 0, twos = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> k;
        if(k == 1)
            ones++;
        if(k == 2)
            twos++;
    }
    if(twos - ones >= 0)
    {
        s = ones;
    }
    else
    {
        s = twos + (ones - twos)/3;
    }
    cout << s;
    return 0;
}