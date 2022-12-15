#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long)(1ll << 32ll);

stack<long long> st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int l;

	cin >> l;

	long long curr = 1, ans = 0;
	st.push(curr);
	

	for(int i = 0; i < l; i++){
		string s;

		cin >> s;

		if(s == "for"){
			long long n;

			cin >> n;

			curr *= n;
			if(curr >= inf){
				curr = inf;
			}
			st.push(curr);
			continue;
		}
		if(s == "end"){
			st.pop();
			curr = st.top();
			continue;
		}
		if(s == "add"){
			ans += curr;
			if(ans >= inf){
				ans = inf;
			}
			continue;
		}
	}

	if(ans == inf){
		cout << "OVERFLOW!!!\n"; 
	}
	else{
		cout << ans << "\n";
	}

	return 0;
}