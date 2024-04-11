#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int cnt,p[1010];
vector<vector<char> > a[1010];
string s;

inline int dfs(int l,int r)
{
	cnt++;
	int id=cnt;
	if(s[l]=='('&&s[r]==')'&&p[l]==r){
		int now=dfs(l+1,r-1);
		a[id]=a[now];
		return id;
	}
	vector<int> v;
	v.push_back(l-1);
	for(int i=l;i<=r;i++){
		if(s[i]=='(') i=p[i];
		else if(s[i]=='|'){
			v.push_back(i);
		}
	}
	v.push_back(r+1);
	if(v.size()==2){
		vector<pair<int,int> > g;
		int pre=l;
		for(int i=l;i<=r;i++){
			if(s[i]=='('){
				if(i-pre>0) g.push_back(make_pair(pre,i-1));
				int nxt=p[i];
				while(nxt<r&&(s[nxt+1]=='+'||s[nxt+1]=='?'||s[nxt+1]=='*')) nxt++;
				g.push_back(make_pair(i,nxt));
				i=nxt;pre=nxt+1;
			}
			else if(s[i]=='+'||s[i]=='?'||s[i]=='*'){
				if(i-pre>1) g.push_back(make_pair(pre,i-2));
				int nxt=i;
				while(nxt<r&&(s[nxt+1]=='+'||s[nxt+1]=='?'||s[nxt+1]=='*')) nxt++;
				g.push_back(make_pair(i-1,nxt));
				i=nxt;pre=nxt+1;
			}
		}
		if(s[r]!='+'&&s[r]!='?'&&s[r]!='*'&&s[r]!=')'){
			g.push_back(make_pair(pre,r));
		}
		if(g.size()==1){
			if(s[r]=='+'){
				int now=dfs(l,r-1);
				a[id].resize(a[now].size()+2,vector<char>(a[now][0].size()+6,' '));
				for(int i=0;i<a[now].size();i++){
					for(int j=3;j<a[now][0].size()+3;j++){
						a[id][i][j]=a[now][i][j-3];
					}
				}
				a[id][1][0]='+';a[id][1][1]='-';a[id][1][2]='>';
				a[id][1][a[now][0].size()+3]='-';a[id][1][a[now][0].size()+4]='>';a[id][1][a[now][0].size()+5]='+';
				for(int i=2;i<a[now].size()+1;i++){
					a[id][i][0]='|';a[id][i][a[now][0].size()+5]='|';
				}
				a[id][a[now].size()+1][0]='+';a[id][a[now].size()+1][a[now][0].size()+5]='+';
				a[id][a[now].size()+1][1]='<';
				for(int i=2;i<a[now][0].size()+5;i++){
					a[id][a[now].size()+1][i]='-';
				}
			}
			else if(s[r]=='?'){
				int now=dfs(l,r-1);
				a[id].resize(a[now].size()+3,vector<char>(a[now][0].size()+6,' '));
				for(int i=3;i<a[now].size()+3;i++){
					for(int j=3;j<a[now][0].size()+3;j++){
						a[id][i][j]=a[now][i-3][j-3];
					}
				}
				a[id][4][0]='+';a[id][4][1]='-';a[id][4][2]='>';
				a[id][4][a[now][0].size()+3]='-';a[id][4][a[now][0].size()+4]='>';a[id][4][a[now][0].size()+5]='+';
				for(int i=2;i<4;i++){
					a[id][i][0]='|';a[id][i][a[now][0].size()+5]='|';
				}
				a[id][1][0]='+';a[id][1][a[now][0].size()+5]='+';
				a[id][1][a[now][0].size()+4]='>';
				for(int i=1;i<a[now][0].size()+4;i++){
					a[id][1][i]='-';
				}
			}
			else if(s[r]=='*'){
				int now=dfs(l,r-1);
				a[id].resize(a[now].size()+5,vector<char>(a[now][0].size()+6,' '));
				for(int i=3;i<a[now].size()+3;i++){
					for(int j=3;j<a[now][0].size()+3;j++){
						a[id][i][j]=a[now][i-3][j-3];
					}
				}
				a[id][4][0]='+';a[id][4][1]='-';a[id][4][2]='>';
				a[id][4][a[now][0].size()+3]='-';a[id][4][a[now][0].size()+4]='>';a[id][4][a[now][0].size()+5]='+';
				for(int i=2;i<4;i++){
					a[id][i][0]='|';a[id][i][a[now][0].size()+5]='|';
				}
				a[id][1][0]='+';a[id][1][a[now][0].size()+5]='+';
				a[id][1][a[now][0].size()+4]='>';
				for(int i=1;i<a[now][0].size()+4;i++){
					a[id][1][i]='-';
				}
				for(int i=5;i<a[now].size()+4;i++){
					a[id][i][0]='|';a[id][i][a[now][0].size()+5]='|';
				}
				a[id][a[now].size()+4][0]='+';a[id][a[now].size()+4][a[now][0].size()+5]='+';
				a[id][a[now].size()+4][1]='<';
				for(int i=2;i<a[now][0].size()+5;i++){
					a[id][a[now].size()+4][i]='-';
				}
			}
			else{
				a[id].resize(3,vector<char>(r-l+1+4,' '));
				a[id][0][0]='+';a[id][1][0]='+';a[id][2][0]='+';
				a[id][0][r-l+1+3]='+';a[id][1][r-l+1+3]='+';a[id][2][r-l+1+3]='+';
				for(int i=1;i<r-l+1+3;i++){
					a[id][0][i]='-';a[id][2][i]='-';
				}
				for(int i=2;i<r-l+1+2;i++){
					a[id][1][i]=s[l+i-2];
				}
			}
		}
		else{
			int row=0,col=0;
			vector<int> nw;
			for(int i=0;i<g.size();i++){
				nw.push_back(dfs(g[i].first,g[i].second));
			}
			for(int i=0;i<nw.size();i++) row=max(row,(int)a[nw[i]].size());
			for(int i=0;i<nw.size();i++) col+=a[nw[i]][0].size();
			col+=(nw.size()-1)*2;
			a[id].resize(row,vector<char>(col,' '));
			int now=0;
			for(int i=0;i<nw.size();i++){
				for(int ii=0;ii<a[nw[i]].size();ii++){
					for(int j=now;j<now+a[nw[i]][0].size();j++){
						a[id][ii][j]=a[nw[i]][ii][j-now];
					}
				}
				if(i<nw.size()-1){
					a[id][1][now+a[nw[i]][0].size()]='-';a[id][1][now+a[nw[i]][0].size()+1]='>';
					now+=a[nw[i]][0].size()+2;
				}
			}
		}
	}
	else{
		vector<int> g;
		for(int i=0;i<v.size()-1;i++){
			g.push_back(dfs(v[i]+1,v[i+1]-1));
		}
		int row=0,col=0;
		for(int i=0;i<g.size();i++) col=max(col,(int)a[g[i]][0].size());
		for(int i=0;i<g.size();i++) row+=a[g[i]].size();
		row+=(g.size()-1);
		a[id].resize(row,vector<char>(col+6,' '));
		int now=0;
		for(int i=0;i<g.size();i++){
			for(int ii=now;ii<now+a[g[i]].size();ii++){
				for(int j=3;j<a[g[i]][0].size()+3;j++){
					a[id][ii][j]=a[g[i]][ii-now][j-3];
				}
			}
			a[id][now+1][0]='+';a[id][now+1][1]='-';a[id][now+1][2]='>';
			for(int j=a[g[i]][0].size()+3;j<col+3;j++){
				a[id][now+1][j]='-';
			}
			a[id][now+1][col+3]='-';a[id][now+1][col+4]='>';a[id][now+1][col+5]='+';
			if(i<g.size()-1){
				int nxt=now+a[g[i]].size()+1;
				for(int ii=now+2;ii<=nxt;ii++){
					a[id][ii][0]='|';a[id][ii][col+5]='|';
				}
				now=nxt;
			}
		}
	}
	return id;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>s;stack<int> st;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			st.push(i);
		}
		else if(s[i]==')'){
			int x=st.top();st.pop();
			p[x]=i;
		}
	}
	dfs(0,s.size()-1);
	vector<vector<char> > ans;
	ans.resize(a[1].size(),vector<char>(a[1][0].size()+6,' '));
	ans[1][0]='S';ans[1][1]='-';ans[1][2]='>';
	for(int i=0;i<a[1].size();i++){
		for(int j=3;j<a[1][0].size()+3;j++){
			ans[i][j]=a[1][i][j-3];
		}
	}
	ans[1][a[1][0].size()+3]='-';ans[1][a[1][0].size()+4]='>';ans[1][a[1][0].size()+5]='F';
	cout<<ans.size()<<" "<<ans[0].size()<<'\n';
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<<ans[i][j];
		}
		cout<<'\n';
	}
	return 0;
}