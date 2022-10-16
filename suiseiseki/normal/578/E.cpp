#include <set>
#include <cstdio>
#include <algorithm>
const int Maxn=100000;
const int Inf=0x3f3f3f3f;
int n;
char s[Maxn+5];
std::set<int> pos_l,pos_r;
int ans_lis[Maxn+5],ans_len;
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	for(int i=1;i<=n;i++){
		if(s[i]=='L'){
			pos_l.insert(i);
		}
		else{
			pos_r.insert(i);
		}
	}
	if(pos_l.size()<pos_r.size()||(pos_l.size()==pos_r.size()&&(*pos_l.begin())>(*pos_r.begin()))){
		std::swap(pos_l,pos_r);
	}
	pos_l.insert(Inf);
	pos_r.insert(Inf);
	int ans=0,pos=-1,nxt=(*pos_l.begin());
	for(int i=1;i<=n;i++){
		if(nxt==Inf||(*pos_r.lower_bound(nxt)==Inf&&(*pos_l.begin())!=nxt&&(*pos_l.begin())<(*pos_r.begin()))){
			ans++;
			nxt=(*pos_l.begin());
		}
		pos=nxt;
		pos_l.erase(pos);
		nxt=*pos_r.lower_bound(pos);
		ans_lis[++ans_len]=pos;
		std::swap(pos_l,pos_r);
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans_len;i++){
		printf("%d ",ans_lis[i]);
	}
	puts("");
	return 0;
}