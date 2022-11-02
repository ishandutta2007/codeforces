#include <bits/stdc++.h>

const int max_N=1e6;

std::unordered_map<int,int>map;

std::set<int>set[max_N+21];

typedef unsigned long long ull;

struct Hash{
	ull operator()(const std::set<int>&st)const{
		ull res=0;
		for(int i:st)res=res*37+i;
		res=res*41+st.size();
		return res;
	}
};

std::unordered_map<std::set<int>,int,Hash>sg;

int n,tot,ans;

inline void add(int p,int k){
	if(!map[p])map[p]=++tot;
	int index=map[p];
	set[index].insert(k);
}

std::set<int>tmp;

inline int SG(std::set<int>tmp){
	if(sg.count(tmp))return sg[tmp];
	if(tmp.empty())return 0;
	if(tmp.size()==1)return*tmp.begin();
	std::vector<int>vec;
	for(int k=1,max=*--tmp.end();k<=max;++k){
		std::set<int>nex;
		for(auto i:tmp){
			if(i<k)nex.insert(i);
			else if(i>k)nex.insert(i-k);
		}
		vec.push_back(SG(nex));
	}
	std::sort(vec.begin(),vec.end());
	vec.erase(std::unique(vec.begin(),vec.end()),vec.end());
	int res=0;
	for(;res<vec.size()&&vec[res]==res;++res);
	return sg[tmp]=res;
}

int main(){
	scanf("%d",&n);
	while(n--){
		int a,tmp;
		scanf("%d",&a);
		if(~a&1){
			for(tmp=0;~a&1;a>>=1)++tmp;
			add(2,tmp);
		}
		for(int i=3;i*i<=a;i+=2)
			if(!(a%i)){
				for(tmp=0;!(a%i);a/=i)++tmp;
				add(i,tmp);
			}
		if(a>1)add(a,1);
	}
	for(int i=1;i<=tot;++i)ans^=SG(set[i]);
	puts(ans?"Mojtaba":"Arpa");
	return 0;	
}