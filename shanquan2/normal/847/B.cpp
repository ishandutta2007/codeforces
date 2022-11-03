#include<bits/stdc++.h>
using namespace std;

struct fe{
	int x,y;
	bool operator <(const fe &o)const{return x<o.x||x==o.x&&y<o.y;}
};
set<fe> s;
vector<int> a[200005];
int n,m;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		set<fe>::iterator it=s.lower_bound((fe){x,-1});
		if(it==s.begin()){
			a[m].push_back(x);
			s.insert((fe){x,m++});
		}else{
			it--;int y=it->y;
			a[y].push_back(x);
			s.erase(it);s.insert((fe){x,y});
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<a[i].size();j++)printf("%d ",a[i][j]);printf("\n");
	}
	return 0;
}