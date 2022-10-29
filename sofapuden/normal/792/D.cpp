#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000
using namespace std;

int main(){
	ll n, q; cin >> n >> q;
	while(q--){
		ll tmp; cin >> tmp;
		string s;
		cin >> s;
		rep(i, 0, s.length()) {
			if (s[i] == 'L') {
				tmp -= LSB(tmp) / 2;
			}
			else if (s[i] == 'R') {
				tmp += LSB(tmp) / 2;
			}
			else if(tmp != (n+1)/2){
				if (tmp / LSB(tmp) % 4 == 3) {
					tmp -= LSB(tmp);
				}
				else {
					tmp += LSB(tmp);
				}
			}
		}
		cout << tmp << endl;

	}
}