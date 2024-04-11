#include <bits/stdc++.h>
using namespace std;
//Coded in Dongge Jifang 2
//IP address: 192.168.10.233

int h[100005],l[100005],r[100005];
int n;
multiset<int> s;
vector<pair<int,int> > e,f;

int main(){
	#ifndef XUDADIAO
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",h+i,l+i,r+i);
		e.push_back(make_pair(l[i],h[i]));
		e.push_back(make_pair(r[i],-h[i]));
	}
	sort(e.begin(),e.end());
	f.push_back(make_pair(e[0].first,0));
	for(int i=0;i<e.size();i++){
		if(e[i].second>0){
			s.insert(e[i].second);
		}else{
			s.erase(s.find(-e[i].second));
		}
		if(i==e.size()-1||e[i].first!=e[i+1].first){
			int faq;
			if(s.empty()){
				faq=0;
			}else{
				faq=*s.rbegin();
			}
			if(faq!=f.back().second){
				f.push_back(make_pair(e[i].first,f.back().second));
				f.push_back(make_pair(e[i].first,faq));
			}
		}
	}
	printf("%d\n",f.size()-1);
	for(int i=1;i<f.size();i++){
		printf("%d %d\n",f[i].first,f[i].second);
	}
	return 0;
}