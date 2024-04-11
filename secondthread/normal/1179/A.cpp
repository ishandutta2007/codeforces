#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int nElements, nQueries; cin>>nElements>>nQueries;
	deque<int> a;
	vector<pair<int, int> > firstMoves;
	for (int i=0; i<nElements; i++) {
		int temp; cin>>temp;
		a.push_back(temp);
	}
	for (int i=0; i<nElements; i++) {
		int a1=a.front(); a.pop_front();
		int a2=a.front(); a.pop_front();
		firstMoves.push_back({a1, a2});
		a.push_front(max(a1, a2));
		a.push_back(min(a1, a2));
	}

	int maxElement=a.front();
	a.pop_front();
	vector<int> left;
	while (!a.empty()) {
		left.push_back(a.front());
		a.pop_front();
	}
	
	for (int q=0; q<nQueries; q++) {
		ll turn; cin>>turn; turn--;
		if (turn<firstMoves.size()) {
			 cout<<firstMoves[turn].first<<" "<<firstMoves[turn].second<<'\n';
		}
		else {
			int first=maxElement, second=left[(turn-firstMoves.size())%left.size()];
			cout<<first<<" "<<second<<'\n';
		}
	}

	return 0;
}