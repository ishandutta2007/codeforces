#include<bits/stdc++.h>
const int maxn = 1000300;
typedef long long ll;
ll a,b,c;
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> a >> b >> c,c <<= 1;
	c += std::min(a,b) * 2;
	c += a != b;
	std::cout << c << '\n';
}