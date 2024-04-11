#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int x[m], y[m];
		for(i=0; i<m; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}
		map<int, int> count;
		for(i=0; i<n; i++) {
			if(count.end() == count.find(a[i])) {
				count[a[i]] = 0;
			}
			count[a[i]]++;
		}
		map<int, vector<int>> group;
		for(auto i=count.begin(); i!=count.end(); i++) {
			if(group.end() == group.find(i->second)) {
				group[i->second] = {};
			}
			group[i->second].push_back(i->first);
						//printf("%d %d\n", i->first, i->second);
		}
		for(auto i=group.begin(); i!=group.end(); i++) {
			sort(i->second.begin(), i->second.end(), greater<int>());
		}
		map<int, vector<int>> ban;
		for(i=0; i<m; i++) {
			if(ban.end() == ban.find(x[i])) {
				ban[x[i]] = {};
			}
			if(ban.end() == ban.find(y[i])) {
				ban[y[i]] = {};
			}
			ban[x[i]].push_back(y[i]);
			ban[y[i]].push_back(x[i]);
		}
		for(auto i=ban.begin(); i!=ban.end(); i++) {
			sort(i->second.begin(), i->second.end());
		}
		long long answer = 0;
		for(auto i=group.begin(); i!=group.end(); i++) {
			for(auto j=group.begin(); j!=group.end(); j++) {
				for(k=0; k<i->second.size(); k++) {
					for(l=0; l<j->second.size(); l++) {
						int val1 = group[i->first][k];
						int val2 = group[j->first][l];
						//printf("%d %d %d %d\n", i->first, j->first, val1, val2);
						int found = binary_search(ban[val1].begin(), ban[val1].end(), val2);
						if(val1 != val2 && !found) {
							answer = max(answer, (long long)(i->first+j->first)*(val1+val2));
							if(l == 0) {
								goto OUT;
							}
							break;
						}
					}
				}
OUT:;
			}
		}
		printf("%lld\n", answer);
	}
}