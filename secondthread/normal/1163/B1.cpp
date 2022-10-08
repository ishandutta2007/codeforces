#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
const int maxn=100001;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int colors[maxn];
	for (int i=0; i<n; i++) cin>>colors[i];

	map<int, int> counts;
	int max=1;
	set<ii> pairs;
	for (int i=0; i<n; i++) {
		if (counts.find(colors[i])==counts.end()) {
			counts[colors[i]]=1;
			pairs.insert({1, colors[i]});
		}
		else {
			pairs.erase({counts[colors[i]], colors[i]});
			counts[colors[i]]=counts[colors[i]]+1;
			//cout<<"Inserting pair "<<counts[colors[i]]<<" "<<colors[i]<<endl;
			pairs.insert({counts[colors[i]], colors[i]});
		}

		//try removing the first element
		if ((*pairs.begin()).first==1) {
			auto it=pairs.begin();
			it++;
			if (it==pairs.end()||(*it).first==(*--pairs.end()).first) {
				//cout<<"Valid by removing first "<<i<<endl;
				max=i+1;
			}
		}
		//remove from the last
		int num=(*pairs.begin()).first;
		int end=(*--pairs.end()).first;
		auto it=pairs.end();
		it--;
		it--;
		int secondLast=(*it).first;
		if (num==end-1&&secondLast==end-1) {
			max=i+1;
			//cout<<"Valid by removing from last "<<i<<endl;
			//cout<<"\t start "<<num<<" end: "<<end<<" secondLast: "<<secondLast<<endl;
		}

		if (pairs.size()==1) {
			max=i+1;
			//cout<<"Valid because size is 1 "<<i<<endl;
		}
	}

	cout<<max<<endl;
	
	return 0;
}