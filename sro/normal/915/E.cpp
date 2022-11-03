#include <bits/stdc++.h>
using namespace std;

int main(){
	set<pair<int,int> > st;
	int n,q;
	scanf("%d%d",&n,&q);
	int cnt=n;
	while(q--){
		int l,r,mode;
		scanf("%d%d%d",&l,&r,&mode);
		if(mode==1){
			set<pair<int,int> >::iterator it=st.lower_bound(make_pair(l,-0x3f3f3f3f));
			if(it!=st.begin()){
				it--;
				if(it->second<l){
					it++;
				}
			}
			set<pair<int,int> >::iterator ot=st.lower_bound(make_pair(r,0x3f3f3f3f));
			int bg=l,en=r;
			int hv=0;
			while(it!=ot){
				pair<int,int> x=*it;
				hv+=min(x.second,r)-max(x.first,l)+1;
				bg=min(bg,x.first);
				en=max(en,x.second);
				set<pair<int,int> >::iterator it2=it;
				it2++;
				st.erase(it);
				it=it2;
			}
			cnt-=(r-l+1)-hv;
			st.insert(make_pair(bg,en));
		}else{
			set<pair<int,int> >::iterator it=st.lower_bound(make_pair(l,-0x3f3f3f3f));
			if(it!=st.begin()){
				it--;
				if(it->second<l){
					it++;
				}
			}
			set<pair<int,int> >::iterator ot=st.lower_bound(make_pair(r,0x3f3f3f3f));
			int bg=l,en=r;
			int hv=0;
			while(it!=ot){
				pair<int,int> x=*it;
				hv+=min(x.second,r)-max(x.first,l)+1;
				bg=min(bg,x.first);
				en=max(en,x.second);
				set<pair<int,int> >::iterator it2=it;
				it2++;
				st.erase(it);
				it=it2;
			}
			cnt+=hv;
			if(bg!=l){
				st.insert(make_pair(bg,l-1));
			}
			if(en!=r){
				st.insert(make_pair(r+1,en));
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}