#include<bits/stdc++.h>
using namespace std;
int n, x, y;

int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool find_any_solution (int a, int b, int c, int & x0, int & y0, int & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >>n;
    x = n;
    for (int i = 2; i <= sqrt(n); ++i){
        if (n % i == 0){
            x = i;
            break;
        }
    }
    if (x == n)return cout <<"NO", 0;
    int m = n;
    while (m % x == 0){
        m /= x;
    }
    if (m == 1)return cout <<"NO", 0;
    y = m;
    for (int i = 2; i <= sqrt(m); ++i){
        if (m % i == 0){
            y = i;
            break;
        }
    }
    m = n - 1;
    for (int i = 1; i <= x; ++i){
        if ((m - i * y) % x == 0){
            cout <<"YES"<<endl;
            cout <<2<<endl;
            cout <<i<<" "<<n / y<<endl;
            cout <<(m - i * y) / x<<" "<<n / x<<endl;
            return 0;
        }
    }
    cout <<"NO";
}