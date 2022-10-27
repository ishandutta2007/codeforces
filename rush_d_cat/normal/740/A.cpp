#include <iostream>
#include <cstdio>
using namespace std;
const int NICO = 200002;
typedef long long ll;
ll n, a ,b, c;
ll min(ll a, ll b){return a<b?a:b;}
int main()
{
    cin >> n >> a >> b >> c;
    if(n%4==0) cout << 0 << endl;
    if(n%4==1)
    {
        cout << min(3*a,min(c,a+b)) << endl;
    }
    if(n%4==2)
    {
        cout << min(b,min(2*c,2*a)) << endl;
    }
    if(n%4==3)
    {
        cout << min(a,min(b+c,3*c)) << endl;
    }
}