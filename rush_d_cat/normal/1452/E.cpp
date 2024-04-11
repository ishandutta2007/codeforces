#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000 + 10;
int n,m,k;
pair<int,int> interval[N];
int ins(pair<int,int> A,pair<int,int> B){
	int l=max(A.first,B.first);
	int r=min(A.second,B.second);
	return max(r-l+1,0);
}
int len(pair<int,int> p) {
	return p.second - p.first + 1;
}
int tag[N]={0};
void tag_it(pair<int,int> cur, pair<int,int> nex) {
	//printf("tag [%d, %d] [%d, %d]\n", cur.first,cur.second,nex.first,nex.second);
	int cur_position=cur.first;
	if(nex.first > cur.second) {
		if(len(cur) >= len(nex)) {
			int p1=cur_position + nex.first - cur.second; if(p1<=n) tag[p1] ++;
			int p2=cur_position + nex.second+1-cur.second; if(p2<=n) tag[p2] --;
			int p3=cur_position + nex.first+1-cur.first; if(p3<=n) tag[p3]--;
			int p4=cur_position + nex.second-cur.first+2; if(p4<=n) tag[p4]++;
			//printf("%d %d %d %d\n", p1,p2,p3,p4);
		} else {
			int p1=cur_position + nex.first - cur.second; if(p1<=n) tag[p1] ++;
			int p2=cur_position + nex.first+1-cur.first; if(p2<=n) tag[p2] --;
			int p3=cur_position + nex.second+1-cur.second; if(p3<=n) tag[p3]--;
			int p4=cur_position + nex.second-cur.first+2; if(p4<=n) tag[p4]++;			
		}
	}else{
		
		if(len(cur) >= len(nex)) {
			int p1=cur_position+1; if(p1<=n) tag[p1] ++;
			int p2=cur_position+nex.second-cur.second+1; if(p2<=n) tag[p2]--;
			int p3=cur_position+nex.first-cur.first+1; if(p3<=n) tag[p3]--;

			int inslen=ins(cur,nex);
			int p4=nex.second-inslen+1+1; if(p4<=n) tag[p4]++;
		}else{
			int p1=cur_position+1; if(p1<=n) tag[p1] ++;
			int p2=cur_position+nex.first-cur.first+1; if(p2<=n) tag[p2]--;
			int p3=cur_position+nex.second-cur.second+1; if(p3<=n) tag[p3]--;

			int inslen=ins(cur,nex);
			int p4=nex.second-inslen+1+1; if(p4<=n) tag[p4]++;
		}
		
	}
}
int solve(int x){
	int sum=0;
	pair<int,int> cur=make_pair(x,x+k-1);
	for(int i=1;i<=m;i++)sum+=ins(cur,interval[i]);
	//printf("sum=%d\n", sum);
	for(int i=0;i<=n;i++){
		tag[i]=0;
	}
	for(int i=1;i<=m;i++){
		if(interval[i].first >= x && interval[i].second >= x+k-1) {
			tag_it(cur, interval[i]);
		}
	}
	for(int i=1;i<=n;i++)tag[i]=tag[i-1]+tag[i];
	for(int i=1;i<=n;i++)tag[i]=tag[i-1]+tag[i];
	int mx=0;
	for(int i=1;i<=n;i++)
		mx=max(mx,tag[i]);
	return sum+mx;
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&interval[i].first,&interval[i].second);
	}
	sort(interval+1,interval+1+m);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,solve(i));
	}
	printf("%d\n", ans);
}