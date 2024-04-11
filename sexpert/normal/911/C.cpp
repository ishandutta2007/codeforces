#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	vector<int> nums;
	for(int i = 0; i < 3; i++)
	{
		scanf("%d", &k);
		nums.push_back(k);
	}
	sort(nums.begin(), nums.end());
	if(nums[0] > 3) printf("NO");
	else if(nums[0] == 3)
	{
		if(nums[2] == 3) printf("YES");
		else printf("NO");
	}
	else if(nums[0] == 2)
	{
		if(nums[1] > 4) printf("NO");
		else if(nums[1] == 4)
		{
			if(nums[2] > 4) printf("NO");
			else printf("YES");
		}
		else if(nums[1] == 3) printf("NO");
		else printf("YES");
	}
	else printf("YES");
}