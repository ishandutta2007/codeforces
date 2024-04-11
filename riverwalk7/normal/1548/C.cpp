#include <iostream>
#include <fstream>
#define MAXN 1000100
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll poly_a[MAXN*3]; //poly_a[i] equals the coefficient of y^i (1+y)^(3n+3)-1
ll poly_b[MAXN*3]; //poly_b[i] equals the coefficient of y^i in ((1+y)^(3n+3)-1)/((1+y)^3-1)
ll inv[MAXN*3];
int N, Q, x;
void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main()
{
    fast_IO();
    cin>>N;
    ll D = 3*N+3;
    poly_a[0] = 1;
    for(int i=1; i<=D; i++)
    {
        if(i == 1) inv[i] = 1;
        else inv[i] = MOD-(MOD/i*inv[MOD%i]%MOD);
        poly_a[i] = poly_a[i-1]*(D-i+1)%MOD*inv[i]%MOD;
    }
    poly_a[0] = 0; //probably unnecessary, but be consistent with the definition provided above to avoid confusing myself
    for(int i=D-3; i>=0; i--)
    {
        poly_b[i] = poly_a[i+3]-(poly_b[i+2]*3+poly_b[i+1]*3);
        poly_b[i] = (poly_b[i]%MOD+MOD)%MOD;
    }
    cin>>Q;
    for(int i=0; i<Q; i++)
    {
        cin>>x;
        cout<<poly_b[x]<<endl;
    }
}