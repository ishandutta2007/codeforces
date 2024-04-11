#include <cstdio>
#include <map>
#include <string>

using namespace std;

char s[20];

int main(){
	int n;
	scanf("%d", &n);
	map<string, int> lst;
	for (int i = 0; i < n; ++i){
		scanf("%s", s);
		lst[string(s)] = i;
	}
	map<int, string> ans;
	for (map<string, int>::iterator p = lst.begin(); p != lst.end(); ++p)
		ans[-p->second] = p->first;
	for (map<int, string>::iterator p = ans.begin(); p != ans.end(); ++p)
		puts(p->second.c_str());
	return 0;
}