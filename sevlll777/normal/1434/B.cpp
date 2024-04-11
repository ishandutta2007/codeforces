#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	char c[n*2];
	int num[n*2];
	for(int i = 0; i < n*2; i++) {
		cin>>c[i];
		if(c[i] == '-')
			cin>>num[i];
	}

	vector<int> sol;
	stack<int> s;
	for(int i = n*2-1; i >= 0; i--) {
		if(c[i] == '-') {
			s.push(num[i]);
		} else {
			if(s.size() <= 0) {
				cout<<"NO"<<endl;
				return 0;
			}
			sol.push_back(s.top());
			s.pop();
		}
	}

	reverse(sol.begin(), sol.end());

	set<int> caca;
	int index = 0;
	for(int i = 0; i < n*2; i++) {
		if(c[i] == '-') {
			int q = *caca.begin();
			//cerr<<"QUITO "<<q<<endl;
			caca.erase(caca.begin());
			if(q != num[i]) {
				cout<<"NO"<<endl;
				return 0;
			}
		} else {
			caca.insert(sol[index]);
			index++;
		}
	}

	cout<<"YES"<<endl;
	for(int i = 0; i < n; i++) {
		cout<<sol[i]<<' ';
	}
	cout<<endl;
}