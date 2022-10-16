#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <random>
#include <algorithm>
const int Maxn=1000000;
int c,n;
int f[Maxn+5],res[Maxn+5],ans[Maxn+5];
int num[Maxn+5],min_p[Maxn+5];
bool np[Maxn+5];
int p[Maxn+5],p_len;
std::vector<int> vec[Maxn+5];
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=Maxn;i++){
		if(!np[i]){
			p[++p_len]=i;
			min_p[i]=p_len;
		}
		for(int j=1,x;j<=p_len&&1ll*i*p[j]<=Maxn;j++){
			x=i*p[j];
			np[x]=1;
			min_p[x]=j;
			if(i%p[j]==0){
				break;
			}
		}
	}
}
int main(){
	init();
	scanf("%d%d",&c,&n);
	int val=(int)sqrt(c);
	for(int i=val;i>1;i--){
		for(int j=1;j<=c/i/i;j++){
			num[i*i*j]=i;
		}
	}
	std::vector<int> v,pos;
	for(int i=1;i<=c;i++){
		if(num[i]==0){
			pos.push_back(i);
			f[i]=v.size();
			v.push_back(i);
		}
	}
	printf("%d\n",(int)v.size());
	for(int x:v){
		printf("%d ",x);
	}
	puts("");
	fflush(stdout);
	for(int i=0;i<(int)v.size();i++){
		scanf("%d",&res[i]);
	}
	for(int i:pos){
		f[i]=res[f[i]];
	}
	int sum=f[1];
	for(int i:pos){
		f[i]^=sum;
	}
	for(int i:pos){
		std::vector<int> d;
		{
			int x=i;
			while(x>1){
				d.push_back(p[min_p[x]]);
				x/=p[min_p[x]];
			}
		}
		for(int j=0;j<(int)(1<<d.size());j++){
			int x=i;
			for(int k=0;k<(int)d.size();k++){
				if((j>>k)&1){
					x/=d[k];
				}
			}
			if(x!=i){
				f[i]^=f[x];
			}
		}
	}
	f[1]=sum;
	for(int I=(int)pos.size()-1;I>=0;I--){
		int i=pos[I];
		for(int j=i+i;j<=c;j+=i){
			f[i]^=f[j];
		}
	}
	for(int i=1;i<=c;i++){
		int tmp=1,x=i;
		while(num[x]){
			int t=num[x];
			tmp*=t;
			while(x%t==0){
				x/=t;
			}
		}
		tmp*=x;
		vec[tmp].push_back(i);
	}
	std::vector<int> bad_lis;
	std::vector<std::vector<std::bitset<265> > > t_lis;
	std::vector<std::bitset<265> > able_lis;
	int tot=0;
	for(int i=1;i<=c;i++){
		if(!vec[i].empty()){
			std::pair<int,std::bitset<265> > b[20];
			std::vector<std::pair<int,int> > lis_b;
			auto insert=[&](int x,std::bitset<265> y)->bool{
				for(int j=19;j>=0;j--){
					if((x>>j)&1){
						if(!b[j].first){
							b[j]=std::make_pair(x,y);
							return 1;
						}
						else{
							x^=b[j].first;
							y^=b[j].second;
						}
					}
				}
				return 0;
			};
			for(int j=0;j<(int)vec[i].size();j++){
				std::bitset<265> tmp;
				tmp.set(j);
				if(!insert(vec[i][j],tmp)){
					lis_b.push_back(std::make_pair(vec[i][j],j));
				}
			}
			std::mt19937 rnd(102010);
			if(lis_b.empty()){
				int val=f[i];
				std::bitset<265> st;
				for(int j=19;j>=0;j--){
					if((val>>j)&1){
						val^=b[j].first;
						st^=b[j].second;
					}
				}
				for(int j=st._Find_first();j<265;j=st._Find_next(j)){
					ans[vec[i][j]]=vec[i][j];
					n--;
				}
			}
			else{
				tot+=vec[i].size();
				bad_lis.push_back(i);
				std::vector<std::bitset<265> > t;
				t.resize(vec[i].size()+1);
				std::bitset<265> able;
				for(int _=0;_<100;_++){
					int val=f[i];
					std::bitset<265> st;
					for(int j=0;j<(int)lis_b.size();j++){
						if(rnd()&1){
							val^=lis_b[j].first;
							st.set(lis_b[j].second);
						}
					}
					for(int j=19;j>=0;j--){
						if((val>>j)&1){
							val^=b[j].first;
							st^=b[j].second;
						}
					}
					t[st.count()]=st;
					able[st.count()]=1;
				}
				t_lis.push_back(t);
				able_lis.push_back(able);
				lis_b.clear();
			}
		}
	}
	std::bitset<40005> cur;
	cur.set(0);
	std::vector<std::bitset<40005> > g;
	g.resize(bad_lis.size());
	for(int i=0;i<(int)bad_lis.size();i++){
		g[i]=cur;
		std::bitset<40005> nxt;
		for(int j=able_lis[i]._Find_first();j<265;j=able_lis[i]._Find_next(j)){
			nxt|=cur<<j;
		}
		cur=nxt;
	}
	for(int i=(int)bad_lis.size()-1;i>=0;i--){
		int sz=-1;
		for(int j=able_lis[i]._Find_first();j<265;j=able_lis[i]._Find_next(j)){
			if(g[i][n-j]){
				sz=j;
				break;
			}
		}
		for(int j=t_lis[i][sz]._Find_first();j<265;j=t_lis[i][sz]._Find_next(j)){
			ans[vec[bad_lis[i]][j]]=vec[bad_lis[i]][j];
		}
		n-=sz;
	}
	for(int i=1;i<=c;i++){
		if(ans[i]){
			printf("%d ",i);
		}
	}
	puts("");
	return 0;
}