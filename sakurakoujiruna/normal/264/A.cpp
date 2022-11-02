#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	string s;
	cin >> s;
	deque <int> dq;
	for(int i = s.size() - 1; i >= 0; i --)
		if(s[i] == 'l')
			dq.push_back(i);
		else
			dq.push_front(i);
	for(int i = 0; i < dq.size(); i ++)
		cout << dq[i] + 1 << '\n';
	return 0;
}