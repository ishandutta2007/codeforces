#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, m = 1000000000, mdiff = 100000;
	vector<int> nums, poss;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &a);
		nums.push_back(a);
		m = min(a, m);
	}
	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i] == m) poss.push_back(i);
	}
	for(int i = 0; i < poss.size() - 1; i++)
	{
		mdiff = min(mdiff, poss[i + 1] - poss[i]);
	}
	printf("%d", mdiff);
}