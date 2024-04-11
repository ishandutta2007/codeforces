#include <iostream>
#include <set>

using namespace std;

set < int > S;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		int a;
		scanf("%d", &a);
		S.insert(a);
	}
	S.erase(S.begin());
	if (S.empty()) cout << "NO" << endl; else
		printf("%d\n", * S.begin());
	return 0;
}