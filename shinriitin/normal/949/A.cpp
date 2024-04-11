#include <bits/stdc++.h>

template<class T>inline void read(T&x){
	int f=1; char c;
	while(!isdigit(c=getchar()))
		if(c=='-')f=-1;
	for(x=c-48;isdigit(c=getchar());x=x*10+c-48);
	x*=f;
}

const int max_N = 2e5 + 21;

int n,tot,cnt[2];

char s[max_N];

std::vector<int>ans[max_N];

std::queue<int>que[2];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)++cnt[s[i]-'0'];
	tot=cnt[0]-cnt[1];
	if(tot<=0)return puts("-1"),0;
	for(int i=1;i<=tot;++i)que[0].push(i);
	for(int i=1;i<=n;++i){
		int pos=s[i]-'0';
		if(que[pos].empty())
			return puts("-1"),0;
		int x=que[pos].front();
		que[pos^1].push(x);
		que[pos].pop();
		ans[x].push_back(i);
	}
	if(!que[0].empty())
		return puts("-1"),0;
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i){
		printf("%d",(int)ans[i].size());
		for(auto&x:ans[i])printf(" %d",x);
		puts("");
	}
	return 0;
}