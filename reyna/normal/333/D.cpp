//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1009;
pair<int,pair<int,int> > sr[Maxn*Maxn];
int n,m;
int check(int k){
	bitset<Maxn> row[Maxn];
	for(int i = 0; i <= k;i++){
		int x = sr[i].second.first,y = sr[i].second.second;
		row[x].set(y);
	}
	for(int i = 0; i < n;i++)
		for(int j = i + 1; j < n;j++)
			if((row[i] & row[j]).count() >= 2)
				return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n;i++)
		for(int j = 0; j < m;j++){
			int p;
			scanf("%d",&p);
			sr[i * m + j] = make_pair(-p,make_pair(i,j));
		}
	sort(sr,sr+n*m);
	int l = 0,r = n * m - 1;
	while(l < r - 1){
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << -sr[r].first << endl;
}