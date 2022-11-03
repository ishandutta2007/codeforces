#include <bits/stdc++.h>
using namespace std;

int n,k;

struct person{
	int mx[15],mn[15];
	int sz;
	bool operator<(const person &pers)const{
		for(int i=0;i<k;i++){
			if(mx[i]>pers.mn[i]){
				return 0;
			}
		}
		return 1;
	}
};

set<person> lv;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		person ps;
		ps.sz=1;
		for(int j=0;j<k;j++){
			cin>>ps.mn[j];
			ps.mx[j]=ps.mn[j];
		}
		set<person>::iterator L=lv.lower_bound(ps),R=lv.upper_bound(ps);
		for(set<person>::iterator it=L;it!=R;lv.erase(it++)){
			for(int j=0;j<k;j++){
				ps.mx[j]=max(ps.mx[j],it->mx[j]);
				ps.mn[j]=min(ps.mn[j],it->mn[j]);
			}
			ps.sz+=it->sz;
		}
		lv.insert(ps);
		set<person>::iterator it=lv.end();
		it--;
		cout<<it->sz<<endl;
	}
	return 0;
}