#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char c[n];
	bool a[26] = {false};
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		if(c[i] >= 'A' && c[i] <= 'Z') c[i] = c[i] - 'A' + 'a';
		a[c[i]-'a'] = true;
	}
	bool flag = true;
	for(int i=0;i<26;i++) if(not a[i]) flag = false;
	cout<<(flag ? "YES" : "NO")<<endl;
	return 0;
}