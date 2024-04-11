#include <iostream>
#include <vector>
using namespace std;

const int N = 128;
int cnt[N];

int main()
{
	ios :: sync_with_stdio(false);
	string str;
	cin >> str;
	for(int i = 0; i < str.size(); i ++)
		cnt[str[i]] ++;
	vector <char> odd;
	for(char c = 'a'; c <= 'z'; c ++)
		if(cnt[c] & 1)
		{
			odd.push_back(c);
			cnt[c] --;
		}
	for(int i = 0; i < odd.size() / 2; i ++)
		cnt[odd[i]] += 2;
	if(odd.size() & 1)
		str[str.size() / 2] = odd[odd.size() / 2];
	//cout << odd[odd.size() / 2] << '\n';
	int acc = 0;
	for(char c = 'a'; c <= 'z'; c ++)
		for(int i = 0; i < cnt[c] / 2; i ++)
		{
			str[acc] = str[str.size() - acc - 1] = c;
			acc ++;
		}
	cout << str << '\n';
	return 0;
}