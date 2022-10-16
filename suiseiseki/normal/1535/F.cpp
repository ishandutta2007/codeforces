#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n,m;
std::map<std::string,std::vector<std::string> > mp_S;
int ch[Maxn+5][26];
std::vector<int> node_lis[Maxn+5],cur_lis[Maxn+5];
int id_tot;
int calc_num(int pos,int l,int r){
	return std::lower_bound(node_lis[pos].begin(),node_lis[pos].end(),r)-std::lower_bound(node_lis[pos].begin(),node_lis[pos].end(),l);
}
ll solve(std::vector<std::string> str_lis){
	std::sort(str_lis.begin(),str_lis.end());
	int n=(int)str_lis.size(),m=str_lis.front().size();
	while(id_tot>0){
		memset(ch[id_tot],0,sizeof ch[id_tot]);
		node_lis[id_tot].clear();
		id_tot--;
	}
	id_tot++;
	for(int i=0;i<n;i++){
		cur_lis[i].resize(m+1);
		cur_lis[i][m]=1;
		int u=1;
		node_lis[u].push_back(i);
		for(int j=m-1;j>=0;j--){
			if(ch[u][str_lis[i][j]-'a']==0){
				ch[u][str_lis[i][j]-'a']=++id_tot;
			}
			u=ch[u][str_lis[i][j]-'a'];
			cur_lis[i][j]=u;
			node_lis[u].push_back(i);
		}
	}
	ll ans=1ll*n*(n-1);
	std::vector<std::pair<int,int> > st;
	st.push_back(std::make_pair(n,-1));
	for(int i=n-2;i>=0;i--){
		int lcp=0;
		while(lcp<m&&str_lis[i][lcp]==str_lis[i+1][lcp]){
			lcp++;
		}
		while(st.back().second>=lcp){
			st.pop_back();
		}
		st.push_back(std::make_pair(i+1,lcp));
		std::vector<int> unord_lis;
		for(int j=1;j<m;j++){
			if(str_lis[i][j]<str_lis[i][j-1]){
				unord_lis.push_back(j);
			}
		}
		unord_lis.push_back(m);
		for(int j=1;j<(int)st.size();j++){
			int l=st[j].first,r=st[j-1].first;
			lcp=st[j].second;
			if(lcp<m){
				lcp=*std::upper_bound(unord_lis.begin(),unord_lis.end(),lcp);
			}
			ans-=calc_num(cur_lis[i][lcp],l,r);
		}
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		static char s[Maxn+5],t[Maxn+5];
		scanf("%s",s);
		m=0;
		while(s[m++]!='\0');
		m--;
		for(int i=0;i<m;i++){
			t[i]=s[i];
		}
		std::sort(t,t+m);
		mp_S[t].push_back(s);
	}
	ll ans=0;
	std::map<std::string,std::vector<std::string> >::iterator it;
	it=mp_S.begin();
	int sum=0;
	while(it!=mp_S.end()){
		ans+=solve(it->second);
		ans+=1337ll*sum*((it->second).size());
		sum+=(it->second).size();
		it++;
	}
	printf("%lld\n",ans);
	return 0;
}