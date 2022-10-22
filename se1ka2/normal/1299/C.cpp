#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll a[1000002];
P p[1000002];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    int k = 0;
    for(int i = n - 1; i >= 0; i--){
        p[k] = P(a[i], 1);
        while(k > 0 && p[k].first * p[k - 1].second > p[k - 1].first * p[k].second){
            p[k - 1].first += p[k].first;
            p[k - 1].second += p[k].second;
            k--;
        }
        k++;
    }
    for(int i = k - 1; i >= 0; i--){
        for(int j = 0; j < p[i].second; j++) printf("%.15f\n", p[i].first * 1.0 / p[i].second);
    }
}