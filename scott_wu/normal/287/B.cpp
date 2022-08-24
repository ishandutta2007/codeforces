#include <iostream>
#include<cstdlib>

using namespace std;

int main()
{
    __int64 n,k;
    cin >> n >> k;n--;
    if ( k*(k-1)/2 < n){
        cout << "-1\n"; return 0;}
    __int64 l = 0, r = k-1;
    while (l < r)
    {
        long long mid = (l + r) / 2;
         if (k * (k-1) / 2 - (k - mid) * (k - mid - 1) / 2 >= n) 
           r = mid;
           else l = mid +1;
        }
        cout << l << "\n";//printf("%I64d\n",l);
        return 0;
    }