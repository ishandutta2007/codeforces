#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=52;
int n;
vector<pair<int,pair<int,int> > > a;
struct Answer{
	vector<pair<int,int> > a;
}ans[Maxn*Maxn+5];
int len;
pair<int,int> Merge(pair<int,int> l,pair<int,int> r){
	return make_pair(min(l.first,r.first),max(l.second,r.second));
}
pair<int,int> Reverse(pair<int,int> x){
	return make_pair(n-x.second+1,n-x.first+1);
}
void work(vector<pair<int,pair<int,int> > > a){
	/*printf("%u\n",a.size());
	for(int i=0;i<(int)a.size();i++){
		printf("%d %d %d\n",a[i].first,a[i].second.first,a[i].second.second);
	}
	puts("");*/
	if(a.size()==1){
		return;
	}
	int pos_1,pos_2;
	for(int i=1;i<(int)a.size();i++){
		pos_1=pos_2=-1;
		for(int j=0;j<(int)a.size();j++){
			if(a[j].first==i){
				pos_1=j;
			}
			if(a[j].first==i+1){
				pos_2=j;
			}
		}
		if(pos_2==pos_1+1){
			vector<pair<int,pair<int,int> > > nxt;
			for(int j=0;j<pos_1;j++){
				if(a[j].first<=i){
					nxt.push_back(a[j]);
				}
				else{
					nxt.push_back(make_pair(a[j].first-1,a[j].second));
				}
			}
			nxt.push_back(make_pair(a[pos_1].first,Merge(a[pos_1].second,a[pos_2].second)));
			for(int j=pos_2+1;j<(int)a.size();j++){
				if(a[j].first<=i){
					nxt.push_back(a[j]);
				}
				else{
					nxt.push_back(make_pair(a[j].first-1,a[j].second));
				}
			}
			work(nxt);
			return;
		}
		if(pos_1<pos_2){
			continue;
		}
//		printf("%d\n",i);
		len++;
		if(pos_2!=0){
			ans[len].a.push_back(make_pair(1,a[pos_2].second.first-1));
		}
		ans[len].a.push_back(make_pair(a[pos_2].second.first,a[pos_1].second.first-1));
		ans[len].a.push_back(a[pos_1].second);
		if(pos_1!=(int)a.size()-1){
			ans[len].a.push_back(make_pair(a[pos_1].second.second+1,n));
		}
		vector<pair<int,pair<int,int> > > nxt;
		if(pos_1!=(int)a.size()-1){
			for(int j=pos_1+1;j<(int)a.size();j++){
				if(a[j].first<=i){
					nxt.push_back(make_pair(a[j].first,make_pair(a[j].second.first-a[pos_1].second.second\
					,a[j].second.second-a[pos_1].second.second)));
				}
				else{
					nxt.push_back(make_pair(a[j].first-1,make_pair(a[j].second.first-a[pos_1].second.second\
					,a[j].second.second-a[pos_1].second.second)));
				}
			}
		}
		nxt.push_back(make_pair(a[pos_1].first,make_pair(n-a[pos_1].second.second+1\
		,a[pos_2].second.second-a[pos_2].second.first+1+n-a[pos_1].second.first+1)));
		for(int j=pos_2+1;j<pos_1;j++){
			if(a[j].first<=i){
				nxt.push_back(make_pair(a[j].first,make_pair(a[j].second.first-a[pos_2].second.second+n-a[pos_1].second.first+1\
				+a[pos_2].second.second-a[pos_2].second.first+1
				,a[j].second.second-a[pos_2].second.second+n-a[pos_1].second.first+1+a[pos_2].second.second-a[pos_2].second.first+1)));
			}
			else{
				nxt.push_back(make_pair(a[j].first-1,make_pair(a[j].second.first-a[pos_2].second.second+n-a[pos_1].second.first+1\
				+a[pos_2].second.second-a[pos_2].second.first+1
				,a[j].second.second-a[pos_2].second.second+n-a[pos_1].second.first+1+a[pos_2].second.second-a[pos_2].second.first+1)));
			}
		}
		if(pos_2!=0){
			int len=n-a[pos_2].second.first+1;
			for(int j=0;j<pos_2;j++){
				if(a[j].first<=i){
					nxt.push_back(make_pair(a[j].first,make_pair(a[j].second.first+len,a[j].second.second+len)));
				}
				else{
					nxt.push_back(make_pair(a[j].first-1,make_pair(a[j].second.first+len,a[j].second.second+len)));
				}
			}
		}
		work(nxt);
		return;
	}
}
int main(){
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a.push_back(make_pair(x,make_pair(i,i)));
	}
	work(a);
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		printf("%d ",ans[i].a.size());
		for(int j=0;j<(int)ans[i].a.size();j++){
			printf("%d ",ans[i].a[j].second-ans[i].a[j].first+1);
		}
		puts("");
	}
	return 0;
}