#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

typedef vector<string> VS;

int n;
char s[100];

int main(){
	scanf("%d", &n);
	map<string, VS> lst;
	for (int i = 0; i < n; ++i){
		scanf("%s", s);
		char *p = strchr(s + 7, '/');
		if (p == NULL)
			p = s + strlen(s);
		string a(s + 7, p), b(p);
		lst[a].push_back(b);
	}
	map<VS, VS> ans;
	for (auto p: lst){
		sort(p.nd.begin(), p.nd.end());
		p.nd.erase(unique(p.nd.begin(), p.nd.end()), p.nd.end());
		ans[p.nd].push_back(p.st);
	}
	int cnt = 0;
	for (auto p: ans)
		cnt += p.nd.size() > 1;
	printf("%d\n", cnt);
	for (auto p: ans)
		if (p.nd.size() > 1){
			for (int i = p.nd.size() - 1; i >= 0; --i)
				printf("http://%s%c", p.nd[i].c_str(), "\n "[!!i]);
		}
	return 0;
}