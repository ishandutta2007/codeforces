#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string getFunc(vector<int> &a){
	static char s[100];
	string ret("0");
	a.push_back(a.back());
	int K = 0, B = 0;
	for (int i = 1; i < a.size() - 1; ++i){
		int t = (a[i + 1] - a[i]) - (a[i] - a[i - 1]);
		if (t & 1)
			++t, ++a[i + 1];
		t >>= 1;
		sprintf(s, "((0%+d)*abs((t%+d)))", t, -i);
		ret = "(" + ret + "+" + string(s) + ")";
		K += t;
		B += t * i;
	}
	sprintf(s, "(((0%+d)*t)+(0%+d))", a[1] - a[0] + K, a[0] - B);
	return ret = "(" + ret + "+" + string(s) + ")";
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> a, b;
	for (int x, y, i = 0; i < n; ++i){
		scanf("%d%d%*d", &x, &y);
		a.push_back(x);
		b.push_back(y);
	}
	printf("%s\n%s", getFunc(a).c_str(), getFunc(b).c_str());
	return 0;
}