#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;

inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}

queue<string> q;
map<string,bool> vis;
vector<string> g[100];
int ans,n,m;

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		string a,b;
		cin>>a>>b;
		g[b[0]-'a'].pb(a);
	}
	
	string x="a"; q.push(x);
	vis[x]=1;
	while(!q.empty()){
		string x=q.front();q.pop();
		if(x.length()==n){
			ans++;continue;
		}
		for(int i=0;i<1;i++){
			for(int j=0;j<g[x[i]-'a'].size();j++){
				string t="";
				if(i>0) t=t+x.substr(0,i);
				t=t+g[x[i]-'a'][j];
				if(i<x.length()-1) t=t+x.substr(i+1);
				if(!vis[t]){
					q.push(t);
					vis[t]=1;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}