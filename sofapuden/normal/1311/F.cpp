#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define in(name, type) type name; cin >> name
#define LOG(x, sep) std::cout << x << sep
#define LOG(x) std::cout << x << "\n"
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl].x << " " << vec[fl].y << sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

struct Tube {
	ll x, y, pos;
};
bool comparex(Tube& s1, Tube& s2) {
	return (s1.x < s2.x);
}
bool comparey(Tube& s1, Tube& s2) {
	if (s1.y == s2.y) {
		return (s1.x < s2.x);
	}
	else {
		return(s1.y < s2.y);
	}
}

int main() {

	ll n;
	cin >> n;

	vector <ll> xcord;
	vector <ll> ycord;
	vector <Tube> sets;
	rep(i, 0, n) {
		in(tmp, ll);
		xcord.push_back(tmp);
	}
	rep(i, 0, n) {
		in(tmp, ll);
		ycord.push_back(tmp);
	}
	rep(i, 0, n) {
		Tube tmp; tmp.x = xcord[i]; tmp.y = ycord[i];
		sets.push_back(tmp);
	}
	sort(all(sets), comparey);
	rep(i,0,n) {
		sets[i].pos = i;
	}
	sort(all(sets), comparex);
	ll maxsum = 0;
	rep(i, 0, n) {
		maxsum += sets[i].x * (-n + 1 + i + sets[i].pos);
	}

	LOG(maxsum);


	return 0;
}