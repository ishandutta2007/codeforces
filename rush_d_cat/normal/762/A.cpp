#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int NICO = 1005;
typedef long long ll;
ll n, k;
vector<ll> vec;
int main()
{
    cin >> n >> k;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            vec.push_back(i);
            if(i*i!=n) vec.push_back(n/i);
        }
    }
    sort(vec.begin(), vec.end());
    if(vec.size()<k) cout << -1 << endl;
    else cout << vec[k-1] << endl;
}