#include<bits/stdc++.h>
using namespace std;

int n,a[100005],b[100005];
char s[500005];
map<pair<int,int>,int> mp;
int get(int x,int y){
	pair<int,int> a(x,y);
	if(mp.find(a)!=mp.end())return mp[a];else return 0;
}
int main(){
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<n;i++){
		scanf("%s",s);
		int x=0,y=0,l=strlen(s);
		for(int j=0;j<l;j++){
			if(s[j]=='('){
				y++;
			}else if(s[j]==')'){
				if(y)y--;else x++;
			}
		}
		if(!x||!y){
			mp[make_pair(x,y)]++;
		}
	}
	ans+=get(0,0)/2;
	for(int i=1;i<=500000;i++){
		ans+=min(get(i,0),get(0,i));
	}
	printf("%d\n",ans);
	return 0;
}