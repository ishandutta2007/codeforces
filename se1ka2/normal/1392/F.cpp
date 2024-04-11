#include <iostream>
using namespace std;
typedef long long ll;

ll h[1000005];

int main()
{
    int n;
    cin >> n;
    ll x = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld", &h[i]);
        x += h[i];
    }
    ll left = -1, right = 1000000000000;
    while(right - left > 1){
        ll mid = (right + left) / 2;
        if((mid + mid + n - 1) * n / 2 > x) right = mid;
        else left = mid;
    }
    for(int i = 0; i < x - (left + left + n - 1) * n / 2; i++) printf("%lld ", right + i);
    for(int i = x - (left + left + n - 1) * n / 2; i < n; i++) printf("%lld ", left + i);
    printf("\n");
}