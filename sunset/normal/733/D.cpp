#include<bits/stdc++.h>
using namespace std;
struct data{
	int val,bh;
	data(){val=bh=0;}
	data(int val,int bh):val(val),bh(bh){}
};
map<pair<int,int> ,pair<data,data> >st;
int n;
void update(int a,int b,data c){
	if(a<b)swap(a,b);
	pair<data,data>& s=st[make_pair(a,b)];
	if(s.first.val<c.val)s.second=s.first,s.first=c;
	else if(s.second.val<c.val)s.second=c;
}
int ans=0,mx1,mx2;
bool check(int x1,int y1,int x2,int y2){
	return max(x1,y1)!=max(x2,y2)||min(x1,y1)!=min(x2,y2);
}
int main(){
	scanf("%d",&n);
	for(int i=1,a[3];i<=n;++i){
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		update(a[0],a[1],data(a[2],i));
		if(check(a[0],a[1],a[1],a[2]))update(a[1],a[2],data(a[0],i));
		if(check(a[1],a[2],a[2],a[0])&&(check(a[0],a[1],a[2],a[0])))
			update(a[2],a[0],data(a[1],i));
	}
	map<pair<int,int> ,pair<data,data> >::iterator it=st.begin();
	for(;it!=st.end();it++){
//		printf("[%d,%d,%d(%d),%d(%d)]\n",it->first.first,
//		it->first.second,it->second.first.val,it->second.first.bh
//		,it->second.second.val,it->second.second.bh);
		int an=it->first.second;
		if(!it->second.second.bh)an=min(an,it->second.first.val);
		else an=min(an,it->second.first.val+it->second.second.val);
		if(!it->second.second.bh){
			if(an>ans)ans=an,mx2=0,mx1=it->second.first.bh;
		} else {
			if(an>ans)ans=an,mx1=it->second.first.bh,mx2=it->second.second.bh;
		}
		//printf("<%d>",an);
	
	}
//	printf("[%d]",ans);
	if(!mx2)printf("1\n%d\n",mx1);
	else printf("2\n%d %d",mx1,mx2);
}