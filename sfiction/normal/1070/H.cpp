#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> pii;

char s[50];

int main(){
	int cas = 1;

	map<string, pii> lst;
	vector<string> a;
	while (cas--){
		int n;
		scanf("%d", &n);

		string t;
		a.clear();
		lst.clear();
		for (int i = 0; i < n; ++i){
			scanf("%s", s);
			a.emplace_back(s);

			auto &b = a.back();
			for (int j = 0; j < b.size(); ++j){
				t.clear();
				for (int k = j; k < b.size(); ++k){
					t.push_back(b[k]);
					auto p = lst.find(t);
					if (p == lst.end())
						lst[t] = make_pair(1, i);
					else if (p->nd.nd != i){
						++p->nd.st;
						p->nd.nd = i;
					}
				}
			}
		}

		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i){
			scanf("%s", s);
			string b = s;
			auto p = lst.find(b);
			if (p == lst.end())
				puts("0 -");
			else
				printf("%d %s\n", p->nd.st, a[p->nd.nd].c_str());
		}
	}
	return 0;
}