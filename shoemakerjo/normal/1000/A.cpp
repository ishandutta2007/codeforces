#include <bits/stdc++.h>
using namespace std;
multiset<string> s;
int main()
{
	int n;
	cin >> n;
	while (n--) {
		string startingSize; cin >> startingSize;
		s.insert(startingSize);
	}
	n = s.size();
	for(int i = 0; i < n; i++){
		string news; cin >> news;
		if(s.find(news) != s.end()) {
			s.erase(s.find(news));
		}
	}
	cout << s.size() << endl;
}