#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

std::string inv(std::string &s) {
	std::string t = s;
	for (char &c : t) {
		if (c == '+') c = '*';
		else c = '+';
	}
	return t;
}

int main()
{
	int K; scanf("%d", &K);
	std::vector<std::string> s = {"+"};
	while (K--) {
		std::vector<std::string> t = s;
		s.clear();
		for (std::string &k : t) {
			s.push_back(k + k);
			s.push_back(k + inv(k));
		}
	}
	for (std::string &k : s) printf("%s\n", k.c_str());
}