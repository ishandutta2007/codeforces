#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair <int,int> > b[2500005];
int a[200005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			int d=a[i]-a[j];
			d=max(-d,d);
			for(auto t:b[d])
			{
				if(i!=t.first&&i!=t.second&&j!=t.first&&j!=t.second)
				{
					puts("YES");
					if(a[t.first]+a[j]==a[t.second]+a[i])
					{
						cout << t.first << " " << j << " " << t.second << " " << i;
						return 0;
					}
					if(a[t.second]+a[j]==a[t.first]+a[i])
					{
						cout << t.second << " " << j << " " << t.first << " " << i;
						return 0;
					}
				}
			}
			b[d].push_back({i,j});
		}
	}
	puts("NO");
	return 0;
}