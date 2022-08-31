#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int n;
int a[maxn];
int cal()
{
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i++)
		if(a[i] == a[i + 1])
			return 1;
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans ^= (a[i] - i + 1);
	//	cout<<i<<" "<<a[i]<<endl;
	return (ans & 1);
}
int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	sort(a + 1, a + n + 1);
	int fl = 0; // 1 :  
	int ns = 0;
	for(int i = 1; i < n; i++)
		if(a[i] == a[i + 1])
		{
			ns = 1;
		//	cout<<"!!!"<<endl;
			a[i]--;
			if(a[i] == -1) fl = 0;
			else
				fl = cal() ^ 1;
			break;
		}
	if(!ns)
		fl = cal();
	if(fl) cout<<"sjfnb"<<endl;
	else cout<<"cslnb"<<endl;
	return 0;
}