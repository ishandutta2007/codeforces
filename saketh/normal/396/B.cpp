#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> frac;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

bool is_prime(ll arg){
    for(ll p=2; p*p <= arg; p++)
        if(arg % p == 0) return false;
    return true;
}

void solve(int x){
    ll v = x, u = x+1;

    while(!is_prime(v)) v--;
    while(!is_prime(u)) u++;

    ll num = u*v + 2*(x-u-v+1);
    ll den = 2*u*v;
    ll g = gcd(num, den);
    cout << num/g << "/" << den/g << "\n";
}

int N, V;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
       cin >> V;
       solve(V);
    }
    cout.flush();
    return 0; 
}