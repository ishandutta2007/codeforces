#include<bits/stdc++.h>

using namespace std;

struct Mint{
	const static int MOD = 1e9+7;
	int value;
	explicit operator int() const {return value;}
	explicit operator bool() const {return value;}
	Mint(int _value = 0) : value(((_value%MOD)+MOD)%MOD){}

	friend Mint pow(Mint a, Mint b){
		Mint ret = 1;
		while(b.value){
			if(b.value&1){
				ret *= a;
			}
			a *= a;
			b.value /= 2;
		}
		return ret;
	}

	friend Mint inv(Mint b){
		return pow(b,Mint(MOD-2));
	}

	inline Mint operator + (const Mint &b) {return Mint(value+b.value);}
	inline Mint operator - () {return Mint(-value);}
	inline Mint operator - (const Mint &b) {return Mint(value-b.value);}
	inline Mint operator * (const Mint &b) {return Mint(1ll*value*b.value%MOD);}
	inline Mint operator / (const Mint &b) {return Mint(*this*inv(b));}

	inline Mint operator & (const Mint &b) {return Mint(value&b.value);}
	inline Mint operator % (const Mint &b) {return Mint(value%b.value);}
	inline Mint operator << (const Mint &b) {return Mint((1ll*value<<b.value)%MOD);}
	inline Mint operator >> (const Mint &b) {return Mint(value>>b.value);}

	inline Mint& operator += (const Mint &b) {return *this = (*this)+b;}
	inline Mint& operator -= (const Mint &b) {return *this = (*this)-b;}
	inline Mint& operator *= (const Mint &b) {return *this = (*this)*b;}
	inline Mint& operator /= (const Mint &b) {return *this = (*this)/b;}
	inline Mint& operator <<= (const Mint &b) {return *this = (*this)<<b;}
	inline Mint& operator >>= (const Mint &b) {return *this = (*this)>>b;}

	friend bool operator == (const Mint &a, const Mint &b){return a.value == b.value;}
	friend bool operator != (const Mint &a, const Mint &b){return a.value != b.value;}

	friend istream& operator >> (istream &s, Mint &a){s >> a.value;return s;}
	friend ostream& operator << (ostream &o, Mint a){o << a.value;return o;}

};

// https://codeforces.com/problemset/problem/1514/B

int main(){
	int t; cin >> t;
	while(t--){
		Mint n, k; cin >> n >> k;
		cout << pow(n,k) << '\n';
	}
}