#include <iostream>
using namespace std;
long long a[100005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		long long s=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			a[i]+=a[i-1];
			s+=i-1;
			if(a[i]<s) flag=0;
		}
		if(flag) puts("yes");
		else puts("NO");
	}
	return 0;
}