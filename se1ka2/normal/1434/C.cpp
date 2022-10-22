#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000000;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        ll a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        ll right = INF / d + 1, left = 0;
        while(right - left > 1){
            ll mid = (right + left) / 2;
            ll s;
            if(mid * d > c){
                s = b * ((c / d) * (d - c % d) + (c / d + 1) * (c % d));
            }
            else{
                s = b * mid * d;
            }
            if(s >= a) right = mid;
            else left = mid;
        }
        if(right == INF / d + 1){
            cout << -1 << endl;
            continue;
        }
        ll damage = right * a;
        ll heal;
        if(left * d > c){
            heal = b * (c * (c / d + 1) / 2 + ((c / d) * (d - c % d) + (c / d + 1) * (c % d)) * (left - c / d)) * b;
        }
        else{
            heal = b * left * (left + 1) / 2 * d;
        }
        cout << damage - heal << endl;
    }
}