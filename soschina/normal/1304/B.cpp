#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
const int N = 101, M = 51;

int n, m;
string s, ans, mid;
set<string> st;
set<string>::iterator it;

int main(){
	scanf("%d%d", &n, &m);
	while(n--){
		cin >> s;
		if((it = st.find(s)) != st.end()){
			ans += s;
			st.erase(it);
		}else{
			reverse(s.begin(), s.end());
			st.insert(s);
		}
	}
	for(it = st.begin(); it != st.end(); it++){
		s = it->substr((m >> 1) + (m & 1));
		reverse(s.begin(), s.end());
		if(s == it->substr(0, m >> 1)){
			mid = *it;
			break;
		}
	}
	cout << (ans.size() << 1) + mid.size() << '\n' << ans << mid;
	for(string::reverse_iterator c = ans.rbegin(); c != ans.rend(); c++) putchar(*c);
	return 0;
}