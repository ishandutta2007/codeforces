#include <set>
#include <map>
#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
const int Maxn=1500;
const int Maxv=1000000;
const int Mod=1000000007;
int Base;
std::mt19937 rnd(time(NULL)+(size_t)(new char));
bool np[Maxv+5];
int p[Maxv+5],p_len;
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=Maxv;i++){
		if(!np[i]){
			p[++p_len]=i;
			if(1ll*i*i>Maxv){
				continue;
			}
			for(int j=i*i;j<=Maxv;j+=i){
				np[j]=1;
			}
		}
	}
	int x=rnd()%p_len+1;
	Base=p[x];
}
int n,m;
int a[Maxn+5][Maxn+5];
int b[Maxn+5][Maxn+5];
int num_a[Maxn+5],num_b[Maxn+5];
int id[Maxn+5];
std::vector<std::pair<int,int> > lis[Maxn+5],op[Maxn+5];
int num[Maxn+5];
bool vis[Maxn+5];
std::vector<std::pair<int,int> > tmp,nxt;
bool in[Maxn+5];
void calc_val(int x,std::pair<int,int> t,int a){
	std::vector<std::pair<int,int> >::iterator it=std::upper_bound(lis[x].begin(),lis[x].end(),t);
	if(it!=lis[x].end()&&(it->first)==t.first&&(it->second)>=t.second){
		return;
	}
	if(it==lis[x].begin()){
		num[x]+=a;
		return;
	}
	it--;
	if((it->first)<=t.first&&(it->second)>=t.second){
		return;
	}
	num[x]+=a;
}
void calc_pair(std::pair<int,int> t,int a){
	for(int i=0;i<=m;i++){
		if(vis[i]){
			continue;
		}
		calc_val(i,t,a);
	}
}
void work_cut(int x){
	nxt.clear();
	int last=-1;
	int j=0;
	for(int i=0;i<(int)op[x].size()&&j<(int)tmp.size();i++){
		if(op[x][i].second<tmp[j].first){
			continue;
		}
		while(j<(int)tmp.size()&&tmp[j].second<op[x][i].first){
			nxt.push_back(tmp[j]);
			j++;
		}
		if(j>=(int)tmp.size()){
			break;
		}
		last=std::max(last,tmp[j].first);
		int right=std::min(op[x][i].second,tmp[j].second);
		if(last==tmp[j].first&&right==tmp[j].second){
			nxt.push_back(tmp[j]);
			j++;
			continue;
		}
		if(last==tmp[j].first){
			calc_pair(tmp[j],-1);
		}
		if(right!=last){
			nxt.push_back(std::make_pair(last,right));
			calc_pair(nxt.back(),1);
		}
		last=op[x][i].second+1;
		if(op[x][i].second==tmp[j].second){
			j++;
		}
	}
}
int ans[Maxn+5],ans_len;
bool solve(){
	tmp.clear();
	static int rnk[Maxn+5];
	for(int i=1;i<=m;i++){
		rnk[i]=i;
		num[i]=0;
		vis[i]=0;
	}
	tmp.push_back(std::make_pair(1,n));
	calc_pair(std::make_pair(1,n),1);
	ans_len=0;
	std::shuffle(rnk+1,rnk+1+m,rnd);
	while(!tmp.empty()&&num[0]>0){
		int id=-1;
		for(int i=1;i<=m;i++){
			if(vis[rnk[i]]){
				continue;
			}
			if(num[rnk[i]]==0){
				id=rnk[i];
				break;
			}
		}
		if(id==-1){
			return 0;
		}
		ans[++ans_len]=id;
		work_cut(id);
		vis[id]=1;
		tmp=nxt;
	}
	printf("%d\n",ans_len);
	for(int i=ans_len;i>0;i--){
		printf("%d ",ans[i]);
	}
	puts("");
	return 1;
}
int main(){
	clock_t begin=clock(),end;
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			num_a[i]=(1ll*num_a[i]*Base+a[i][j])%Mod;
		}
	}
	int last_n=n;
	bool flag=1;
	for(int i=1,t=1;i<=n;i++,t++){
		num_b[i]=0;
		for(int j=1;j<=m;j++){
			scanf("%d",&b[i][j]);
			num_b[i]=(1ll*num_b[i]*Base+b[i][j])%Mod;
			if(a[t][j]!=b[i][j]){
				flag=0;
			}
		}
		for(int j=1;j<=last_n;j++){
			if(in[j]){
				continue;
			}
			if(num_a[j]==num_b[i]){
				in[j]=1;
				break;
			}
		}
		bool able=1;
		for(int j=1;j<=m;j++){
			if(b[i][j]!=b[i-1][j]){
				able=0;
				break;
			}
		}
		if(able){
			n--;
			i--;
		}
	}
	for(int i=1;i<=last_n;i++){
		if(!in[i]){
			puts("-1");
			return 0;
		}
	}
	if(flag){
		puts("0");
		return 0;
	}
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j+1<=n&&id[j+1]>id[i]){
			j++;
		}
		lis[0].push_back(std::make_pair(i,j));
	}
	for(int j=1;j<=m;j++){
		for(int i=1,k;i<=n;i=k+1){
			k=i;
			while(k+1<=n&&b[k+1][j]>=b[k][j]){
				k++;
			}
			lis[j].push_back(std::make_pair(i,k));
		}
		for(int i=1,k;i<=n;i=k+1){
			k=i;
			while(k+1<=n&&b[k+1][j]==b[k][j]){
				k++;
			}
			op[j].push_back(std::make_pair(i,k));
		}
	}
	end=clock();
	while((end-begin)*1.0/CLOCKS_PER_SEC<1.8){
		if(solve()){
			return 0;
		}
		end=clock();
	}
	puts("-1");
	return 0;
}