#include <iostream>
using namespace std; 
int n, k;
int main()
{
    cin >> n >> k;
    int res = 240 - k;
    int t;
    for(t = 1; t <= n; t++)
    {
        if(t*(t+1)/2 * 5 > res)
        {
            break;
        }
    }
    if(t*(t+1)/2 * 5 > res || t > n) 
    { 
        t --;
    }
    cout << t << endl;

}