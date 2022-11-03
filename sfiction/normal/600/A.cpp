#include <cctype>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 10;

char s[MAXN];
vector<string> num, other;

void check(char *l, char *r){
	if (l == r)
		other.push_back(string());
	else if (r - l == 1 && *l == '0')
		num.push_back("0");
	else{
		bool flag = *l != '0';
		for (char *p = l; flag && p < r; ++p)
			flag &= !!isdigit(*p);
		(flag ? num : other).push_back(string(l, r));
	}
}

void output(vector<string> &s){
	if (s.size() == 0)
		puts("-");
	else{
		for (int i = 0; i < s.size(); ++i)
			printf("%c%s", i ? ',' : '"', s[i].c_str());
		puts("\"");
	}
}

int main(){
	scanf("%s", s);
	int l = 0, r = 0;
	for (; s[r]; ++r)
		if (s[r] == ',' || s[r] == ';'){
			check(s + l, s + r);
			l = r + 1;
		}
	check(s + l, s + r);
	output(num);
	output(other);
	return 0;
}