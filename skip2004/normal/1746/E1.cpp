#include<bits/stdc++.h>
using std::cin;
using std::cout;
int n;
inline int qry(std::vector<int> o) {
	cout << "? " << o.size();
	for(int p : o) cout << ' ' << p;
	cout << std::endl;
	std::string ans;
	std::cin >> ans;
	return ans == "YES";
}
inline int submit(int x) {
	cout << "! " << x << std::endl;
	std::string s;
	cin >> s;
	return s == ":)";
}
using vec = std::vector<int>;
vec add(vec x, vec y) {
	vec p=x;p.insert(p.end(),y.begin(),y.end());
	return p;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	std::vector<int> o, fake;
	for(int i = 1;i <= n;++i) o.push_back(i);
	for(;o.size() + fake.size() >= 10;) {
		vec a[2], b[2];
		for(int i = 0;i < (int) o.size();++i) {
			a[i & 1].push_back(o[i]);
		}
		for(int i = 0;i < (int) fake.size();++i) {
			b[i & 1].push_back(fake[i]);
		}
		int A = qry(add(a[0], b[1]));
		vec z;
		if(A) {
			z = add(a[0], b[1]);
		} else {
			z = add(a[1], b[0]);
		}
		auto x = o, y = fake;
		static int ok[1 << 20];
		for(int p : z) ok[p] = 1;
		o.clear(); fake.clear();
		for(int i : x) {
			if(ok[i]) {
				o.push_back(i);
			} else {
				fake.push_back(i);
			}
		}
		for(int i : y) {
			if(ok[i]) o.push_back(i);
		}
		for(int p : z) ok[p] = 0;
		sort(o.begin(), o.end()); o.erase(unique(o.begin(), o.end()), o.end());
		sort(fake.begin(), fake.end()); fake.erase(unique(fake.begin(), fake.end()), fake.end());
	}
	o.insert(o.end(), fake.begin(), fake.end());
	for(;o.size() >= 4;) {
		vec a[4];
		for(int i = 0;i < (int) o.size();++i) {
			a[i & 3].push_back(o[i]);
		}
		int A = qry(add(a[0], a[1]));
		int B = qry(add(a[0], a[2]));
		o = {};
		if(A) o = add(a[0], a[1]);
		else o = add(a[2], a[3]);
		if(B) o = add(o, add(a[0], a[2]));
		else o = add(o, add(a[1], a[3]));
		sort(o.begin(), o.end());
		o.erase(unique(o.begin(), o.end()), o.end());
	}
	if(o.size() == 3) {
start:
		int ok = 0;
		int a = o[0], b = o[1], c = o[2];
		int A = qry({a});
		int B = qry({b});
		int C = qry({a});
		if(A != C) {
			o = (B ? vec{b} : vec{a, c});
		} else {
			if(A) {
				if(submit(a)) return 0;
				return submit(B ? b : c), 0;
			} else {
				if(B) {
					if(submit(b)) return 0;
					return submit(c), 0;
				} else {
					if(ok) {
						if(submit(b)) return 0;
						return submit(c), 0;
					} else {
						ok = 1;
						goto start;
					}
				}
			}
		}
	}
	if(submit(o[0])) return 0;
	submit(o[1]);
}