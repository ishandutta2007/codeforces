#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAXS = 5E4 + 10;

char s[MAXS];

int main(){
	int n;
	scanf("%d", &n);
	vector<string> lst;
	for (int i = 0; i < n; ++i){
		scanf("%s", s);
		lst.push_back(string(s));
	}
	sort(lst.begin(), lst.end(), [](const string &l, const string &r){return l + r < r + l;});
	for (int i = 0; i < n; ++i)
		printf("%s", lst[i].c_str());
	return 0;
}