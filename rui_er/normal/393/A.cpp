#include <iostream>
#include <map>
using namespace std;

map<char, int> cnt;

int main()
{
	string s;
	cin>>s;
	int l = s.length();
	for(int i=0;i<l;i++) ++cnt[s[i]];
	cout<<min((cnt['n']-1)/2, min(cnt['i'], min(cnt['e']/3, cnt['t'])))<<endl;
	return 0;
}