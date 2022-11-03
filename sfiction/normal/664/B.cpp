#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
	char com[5];
	int A = 1, B = 0;
	vector<int> lst(1, 1);
	while (true){
		scanf("%*s%s", com);
		if (com[0] == '=')
			break;
		lst.push_back(com[0] == '+');
		A += lst.back();
		B += !lst.back();
	}

	int n;
	scanf("%d", &n);
	if (A * (ll)n - B < n || A - B * (ll)n > n)
		puts("Impossible");
	else{
		puts("Possible");
		ll s = n - A + B * (ll)n;
		for (int i = 0; i < lst.size(); ++i){
			if (i){
				putchar(lst[i] ? '+' : '-');
				putchar(' ');
			}

			int t = min(n - 1LL, s);
			s -= t;
			printf("%d ", lst[i] ? t + 1 : n - t);
		}
		printf("= %d\n", n);
	}
	return 0;
}