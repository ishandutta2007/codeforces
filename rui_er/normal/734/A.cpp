#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt = 0;
	for(int i=0;i<n;i++)
		if(s[i] == 'A') ++cnt;
		else --cnt;
	cout<<(cnt > 0 ? "Anton" : (cnt == 0) ? "Friendship" : "Danik")<<endl;
	return 0;
}