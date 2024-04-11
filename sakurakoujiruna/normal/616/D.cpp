#include <iostream>
using namespace std;

const int N = 1000011;

int a[N];
int cnt[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i ++)
		scanf("%d", a + i);

	int ansl = 0;
	int ansr = 0;
	int acc = 0;
	int last = 0;
	for(int i = 0; i < n; i ++)
	{
		if(cnt[a[i]] == 0)
			acc ++;
		cnt[a[i]] ++;

		while(acc > m)
		{
			if(cnt[a[last]] == 1)
				acc --;
			cnt[a[last]] --;
			last ++;
		}

		if(i - last > ansr - ansl)
		{
			ansr = i;
			ansl = last;
		}
	}
	printf("%d %d\n", ansl + 1, ansr + 1);
	return 0;
}