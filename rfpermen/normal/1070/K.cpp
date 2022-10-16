#include<bits/stdc++.h>
using namespace std;

int datas[100005];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int total=0;
	for(int a=0;a<n;a++)
	{
		scanf("%d", &datas[a]);
		total+=datas[a];
	}
	if(total%k!=0)
	{
		printf("No\n");
	}
	else
	{
		int now=0, cnt=0;
		vector<int> out;
		int tr=total/k;
		for(int a=0;a<n;a++)
		{
			now+=datas[a];
			cnt++;
			if(now==tr)
			{
				out.push_back(cnt);
				now=0;
				cnt=0;
			}
			else if(now>tr)
			{
				break;
			}
		}
		if(out.size()!=k)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
			for(int a=0;a<out.size();a++)
			{
				if(a>0) printf(" ");
				printf("%d", out[a]);
			}
			printf("\n");
		}
	}
	return 0;
}