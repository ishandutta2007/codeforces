#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, parity, count = 0, l, r, t;
	vector<int> a;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &t);
		a.push_back(t);
	}
	for(int i = 0; i < a.size() - 1; i++)
	{
		for(int j = i + 1; j < a.size(); j++)
		{
			if(a[i] > a[j]) count++;
		}
	}
	parity = count%2;
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d %d", &l, &r);
		t = r - l;
		parity = (parity + (t*(t + 1))/2)%2;
		if(parity == 1) printf("odd\n");
		else printf("even\n");
	}
}