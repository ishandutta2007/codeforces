#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<pair<int, pair<int, string> > > words;
	int letters[1000];
	for (int i=0; i<1000; i++)
		letters[i]=-1;
	letters['a']=1;
	letters['e']=2;
	letters['i']=3;
	letters['o']=4;
	letters['u']=5;
	for (int i=0; i<n; i++) {
		string line; cin>>line;
		int vowels=0, last=0;
		for (int j=0; j<line.length(); j++) 
			if (letters[line[j]]!=-1) {
				vowels++;
				last=letters[line[j]];
			}
		words.push_back({vowels, {last, line} });
	}
	sort(words.begin(), words.end());
	vector<int> partial;
	vector<pair<int, int> > perfectMatches;
	for (int i=0; i<n; i++) {
		if (i+1<n && words[i].first==words[i+1].first && words[i].second.first==words[i+1].second.first) {
			perfectMatches.push_back({i, i+1});
			i++;
			continue;
		}
		else {
			partial.push_back(i);
		}
	}
	vector<pair<int, int> > partialMatches;
	for (int i=0; i+1<partial.size(); i++) {
		if (words[partial[i]].first==words[partial[i+1]].first) {
			partialMatches.push_back({partial[i], partial[i+1]});
			i++;
		}
	}
	while (perfectMatches.size()>partialMatches.size()) {
		partialMatches.push_back(perfectMatches[perfectMatches.size()-1]);
		perfectMatches.pop_back();
	}
	cout<<perfectMatches.size()<<'\n';
	for (int i=0; i<perfectMatches.size(); i++) {
		cout<<words[partialMatches[i].first].second.second<<" "<<words[perfectMatches[i].first].second.second<<'\n';
		cout<<words[partialMatches[i].second].second.second<<" "<<words[perfectMatches[i].second].second.second<<'\n';
	}


	return 0;
}