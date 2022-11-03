#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	vector<int> a;
	for (int i = 2; i <= 100; ++i){
		bool flag = true;
		for (int j = 2; j < i; ++j)
			if (i % j == 0){
				flag = false;
				break;
			}
		if (flag){
			a.push_back(i);
		}
	}

	char s[20];
	int cnt = 0;
	for (int i = 0; i < a.size(); ++i){
		if (a[i] > 50)
			continue;
		printf("%d\n", a[i]);
		fflush(stdout);
		scanf("%s", s);
		cnt += s[0] == 'y';

		if (a[i] * a[i] > 50)
			continue;

		printf("%d\n", a[i] * a[i]);
		fflush(stdout);
		scanf("%s", s);
		cnt += s[0] == 'y';
	}
	puts(cnt >= 2 ? "composite" : "prime");
	fflush(stdout);
	return 0;
}