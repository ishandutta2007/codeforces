#include <iostream>
using namespace std;
int a[100005],ans[100005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int pos=n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		a[n+1]=n+1;
		int mx=0,lst=1;
		for(int i=1;i<=n+1;i++)
		{
			if(a[i]>mx)
			{
				mx=a[i];
				for(int j=i-1;j>=lst;j--)
					ans[pos--]=a[j];
				lst=i;
			}
		}
		for(int i=1;i<=n;i++) cout << ans[i] << " ";
		puts(""); 
	}
	return 0;
}///