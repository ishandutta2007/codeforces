#include <bits/stdc++.h>

using String = std::string;

inline bool cmp(const String&a,const String&b){
	if(a == "" || b == "")return b == "";
	if(a.length()!=b.length())return a.length()<b.length();
	return a < b;
}

String dp[256][3]; 

//0 can add ! & | without ()
//1 can add & | without ()
//2 can add | without ()

bool vis[256][3];

std::queue<int> queue;

inline void relax(int set,int a,const String&str){
	if(!cmp(str,dp[set][a]))return;
	dp[set][a] = str;
	if(vis[set][a])return;
	queue.push(set*3+a);
	vis[set][a] = 1;
}

inline void spfa(){
	dp[15][0] = "x"; queue.push(15*3); vis[15][0] = 1;
	dp[51][0] = "y"; queue.push(51*3); vis[51][0] = 1;
	dp[85][0] = "z"; queue.push(85*3); vis[85][0] = 1;
	while(!queue.empty()){
		int mask = queue.front();
		int set = mask/3, a = mask%3;
		int n_set, n_a;
		String str = dp[set][a], str1, n_str;
		//add !
		if (!a)
			n_str = "!" + str;
		else
			n_str = "!(" + str + ")";
		n_set = set ^ ((1<<8)-1);
		n_a = 0;
		relax(n_set, n_a, n_str);
		//add &
		for(int s1=0;s1<256;++s1)
			for(int a1=0;a1<3;++a1){
				if((str1 = dp[s1][a1]) == "")
					continue;
				n_set = set & s1;
				n_a = 1;
				String tmp1 = (a<=1? str: "(" + str + ")") + "&" + (a1<=1? str1: "(" + str1 + ")");
				String tmp2 = (a1<=1? str1: "(" + str1 + ")") + "&" + (a<=1? str: "(" + str + ")");
				n_str = cmp(tmp1,tmp2)? tmp1: tmp2;
				relax(n_set, n_a, n_str);
			}
		//add |
		for(int s1=0;s1<256;++s1)
			for(int a1=0;a1<3;++a1){
				if((str1 = dp[s1][a1]) == "")
					continue;
				n_set = set | s1;
				n_a = 2;
				String tmp1 = str + "|" + str1;
				String tmp2 = str1 + "|" + str;
				n_str = cmp(tmp1,tmp2)? tmp1: tmp2;
				relax(n_set, n_a, n_str);
			}
		queue.pop(); vis[set][a] = 0;
	}
}

String ans[256];

inline void init(){
	spfa();
	/*
	freopen("data.txt","w",stdout);
	for(int i=0;i<256;++i){
		String ans;
		for(int j=0;j<3;++j)
			if(cmp(dp[i][j],ans)){
				ans = dp[i][j];
			}
		printf("\"%s\"%c\n",ans.c_str(),",\n"[i==255]);
	}
	*/
	for(int i=0;i<256;++i){
		String tmp;
		for(int j=0;j<3;++j)
			if(cmp(dp[i][j],tmp)){
				tmp = dp[i][j];
			}
		ans[i] = tmp;
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int tmp,mask=0;
		scanf("%d",&tmp);
		for(int i=0;i<8;++i,tmp/=10){
			if(tmp&1)mask|=(1<<i);
		}
		printf("%s\n",ans[mask].c_str());
	}
	return 0;
}