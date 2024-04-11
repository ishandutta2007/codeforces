#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll m[1002][1002];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%lld", &m[i][j]);
    ll a = m[0][1];
    ll b = m[0][2];
    ll c = m[1][2];
    vector<ll> v;
    for(ll i = 1; i * i <= a; i++){
        if(a % i == 0){
            v.push_back(i);
            v.push_back(a / i);
        }
    }
    int z;
    for(ll x : v){
        if(b % x != 0) continue;
        a /= x;
        b /= x;
        if(a * b == c){
            z = x;
            break;
        }
        a *= x;
        b *= x;
    }
    cout << z << " ";
    for(int i = 1; i < n; i++){
        cout << m[0][i] / z << " ";
    }
    cout << endl;
}