#include<bits/stdc++.h>
using namespace std;
int arr[1000];
struct P{
	int x, y;
};
P ans[1000000];
bool operator<(const P &a, const P &b)
{
	if(a.y == b.y)
	{
		if(arr[a.x] == arr[b.x]) return a.x < b.x;
		return arr[a.x] < arr[b.x]; 
	}
	return a.y > b.y;
}
int main()
{
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++)
	{
		if(arr[j] < arr[i])
		{
			ans[cnt++] = (P){i, j};
		}
	}
	sort(ans, ans + cnt);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++)
	{
		printf("%d %d\n", ans[i].x + 1, ans[i].y + 1);
		swap(arr[ans[i].x], arr[ans[i].y]);
	}
	//for(int i = 0; i < n; i++) printf("%d ", arr[i]);
	return 0;
}