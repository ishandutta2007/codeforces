#include<bits/stdc++.h>
using namespace std;
#define vc vector<int>
string ans;
int n,b;
int TOT=0;
void out(string s,int v){
	for(int i=0;i<ans.size();++i)cout<<ans[i];
	cout<<s;
	for(int i=ans.size()+s.size();i<b;++i)cout<<v;
	cout<<endl;
	TOT++;
}
string gt;
void solve(vc p,int st){
	if(st==b)return;
	if(!p.size()){
		for(int i=st;i<b;++i)ans+="0";
		return;
	}
	string now="";
	vc t(0);
	cout<<p[0]<<" ";out("0",1);
	cin>>gt;
	t.push_back(p[0]);
	if(gt[0]=='y')now+="1";
	else now+="0";
	for(int i=1;i<p.size();++i){
		bool ok=0,D=0;
		do{
			ok=0;
			cout<<p[i]<<" ";out(now,1);
			cin>>gt;
			if(gt[0]=='y'){
				ok=1;
				t.pop_back();
				now.pop_back();
				D=1;
			}
		}while(ok==1&&t.size());
		if(st+now.size()==b)continue;
		if(!D){
			cout<<p[i]<<" ";out(now+"0",1);
			cin>>gt;
		}
		t.push_back(p[i]);
		if(D||gt[0]=='y'){
			now+="1";
		}
		else now+="0";
	}
	bool GG=0;
	for(int i=t.size()-1;i>=0;--i){
		cout<<t[i]<<" ";out(now,1);
		cin>>gt;
		if(gt[0]=='y'){
			t.resize(i+1);
			now.resize(i+1);
		}
	}
	ans+=now;
	solve(t,ans.size());
}
int main(){
	cin>>n>>b;
	vc p;
	for(int i=1;i<=n;++i)p.push_back(i);
	solve(p,0);	
	cout<<0<<" "<<ans<<endl;
	cerr<<"TOT: "<<TOT<<endl;
	return 0;
}