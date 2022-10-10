#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, badl, a, sum;
	vector<int> seq;
	seq.reserve(2000000);
	bool lwb = false, bad = false;
	scanf("%d", &n);
	for(int i = 0; i <= n; i++)
	{
		scanf("%d", &a);
		seq[i] = a;
		if(a > 1)
		{
			if(lwb)
			{
				bad = true;
				badl = i;
			}
			else lwb = true;
		}
		else lwb = false;
	}
	if(!bad) printf("perfect");
	else
	{
		printf("ambiguous\n");
		sum = 0;
		for(int i = 0; i <= n; i++)
		{
			a = seq[i];
			while(a--)
			{
				printf("%d ", sum);
			}
			sum += seq[i];
		}
		printf("\n");
		sum = 0;
		for(int i = 0; i <= n; i++)
		{
			a = seq[i];
			if(i == badl)
			{
				a--;
				printf("%d ", sum - 1);
			}
			while(a--)
			{
				printf("%d ", sum);
			}
			sum += seq[i];
		}
	}
}