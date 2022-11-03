#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 1E4 + 10;

char s[MAXN];
bool f[MAXN][2];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	f[n][0] = f[n][1] = true;
	vector<string> lst;
	for (int i = n - 2; i >= 5; --i){
		f[i][0] = f[i + 2][1] || f[i + 2][0] && strncmp(s + i, s + i + 2, 2);
		f[i][1] = f[i + 3][0] || f[i + 3][1] && strncmp(s + i, s + i + 3, 3);
		if (f[i][0])
			lst.push_back(string(s + i, 2));
		if (f[i][1])
			lst.push_back(string(s + i, 3));
	}
	sort(lst.begin(), lst.end());
	lst.erase(unique(lst.begin(), lst.end()), lst.end());
	printf("%d\n", (int)lst.size());
	for (int i = 0; i < lst.size(); ++i)
		puts(lst[i].c_str());
	return 0;
}