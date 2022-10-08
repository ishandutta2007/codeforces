#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

const int maxn=500001;

int a[maxn];
bool hit[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin>>T;
	for (int tt=1; tt<=T; tt++) {
		int n; cin>>n;
		for (int i=0; i<=n; i++)
			a[i]=hit[i]=0;

		vector<vector<int> > incoming;
		for (int i=0; i<=n; i++) incoming.push_back(vector<int>());

		vector<int> next;
		for (int i=0; i<n; i++) {
			int temp; cin>>temp;
			temp--;
			next.push_back(temp);
			if (next[i]==-2) continue;
			incoming[temp].push_back(i);	
		}
		int curNumber=n+1;
		for (int i=n; i>=0; i--) {
			if (hit[i]) continue;
			stack<int> stk;
			stk.push(i);
			while (!stk.empty()) {
				int top=stk.top();
				stk.pop();
				hit[top]=true;
				a[top]=curNumber--;
				for (int i=incoming[top].size()-1; i>=0; i--) {
					stk.push(incoming[top][i]);
				}
			}
		}

		//cout<<"Cand: \n";
		//for (int i=0; i<n; i++)
			//cout<<a[i]<<" ";
		//cout<<'\n';

		vector<ii> pairs;
		for (int i=0; i<=n; i++)
			pairs.push_back({a[i], i});

		sort(pairs.begin(), pairs.end(), std::greater<ii>());
		set<int> indSeen;
		bool works=true;
		for (int i=0; i<=n; i++) {
			ii curPair=pairs[i];
			if (i!=0 && next[curPair.second]!=-2 &&
					(*indSeen.upper_bound(curPair.second))!=next[curPair.second])
				works=false;
			indSeen.insert(curPair.second);
		}

		if (!works) {
			cout<<-1<<'\n';
		}
		else {
			for (int i=0; i<n; i++)
				cout<<a[i]<<" \n"[i==n-1];
		}
		//cout<<endl;

	}
	

	return 0;
}