#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main() {
	 cin.tie(0);
	 ios::sync_with_stdio(false);
	 int t;
	 cin >> t;
	 while(t--) {
		 int n;
		 cin >> n;
		 string s;
		 cin >> s;
		 int cs=1;
		 deque<int>good;
		 for(int i=0;i+1<n;++i) {
			 if(s[i] == s[i+1])
				 good.push_back(i+1);
		 }
		 int cr=-1;
		 int cnt=0;
		 for(int i=0;i<n;++i) {
			 if (s[i] != cr) {
				 while(good.size()&&good.front()<=i)good.pop_front();
				 if (good.size())
					 good.pop_front(), ++cnt;
				 else {
					 int cc=0;
					 for(int j=i;j<n;++j) 
						 if (j==0||s[j] != s[j-1])
							 ++cc;
					 cnt+=(cc+1)/2;
					 break;
				 }
				 cr = s[i];
			 }
			 else {
				 continue;
			 }
		 }
		 cout << cnt << '\n';
	 }
	 return 0;
}