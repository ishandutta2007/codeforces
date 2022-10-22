#include<bits/stdc++.h>
using namespace std;
using nagai=long long;
#define sz(x) (int)(x.size())

const int N=100100;
int need[N];

int sgn(int x){
	return (x>0)-(x<0);
}

int bad(int x){
	return x<0||x>=10;
}

void solve(string a,string b){
	int n=a.size();
	for(auto&x:a)x-='0';
	for(auto&x:b)x-='0';
	need[0]=b[0]-a[0];
	for(int i=0;i+1<n;++i)
		need[i+1]=b[i+1]-a[i+1]-need[i];
	/*
	for(int i=0;i<n;++i)
		cerr<<need[i]<<' ';
	cerr<<'\n';
	*/
	if(need[n-1]!=0){
		cout<<-1<<'\n';
		return;
	}
	vector<pair<int,int>>mem;
	int ptr=0;
	nagai s=0;
	for(int i=0;i<n-1;++i)s+=abs(need[i]);
	int SZ=100000;
	while(true){
		bool ok=false;
		while(ptr<n-1&&need[ptr]==0)++ptr;
		for(int i=ptr;i<n-1;++i){
			if(need[i]==0)continue;
			int s=sgn(need[i]);
			while(need[i]&&!bad(a[i]+s)&&!bad(a[i+1]+s)){
				if(i==0&&a[i]+s==0)break;
				ok=true;
				mem.emplace_back(i,s);
				if((int)mem.size()>SZ)break;
				need[i]-=s;
				a[i]+=s;
				a[i+1]+=s;
			}
		if((int)mem.size()>SZ)break;
		}
		if((int)mem.size()>SZ)break;
		if(!ok)break;
	}
	int x=n-1-count(need,need+n-1,0);
//	assert(x==0);
	if(sz(mem)<SZ)
		assert(sz(mem)==s);
	else assert(s>=SZ);
	/*
	if(sz(mem)>SZ){
		cout<<-1<<'\n';
		return;
	}
	*/
	cout<<s<<'\n';
	for(int i=0;i<min(sz(mem),SZ);++i)
		cout<<mem[i].first+1<<' '<<mem[i].second<<'\n';
}
mt19937 rnd(228);
void stress(){
	for(int i=0;i<100000;++i){
		int n=2;
		string a(n,'?'),b=a;
		for(int j=0;j<n;++j){
			a[j]='0'+rnd()%10;
			b[j]='0'+rnd()%10;
		}
		a[0]='1'+rnd()%9;
		b[0]='1'+rnd()%9;
		ofstream test("test");
		test<<n<<'\n';
		test<<a<<'\n';
		test<<b<<'\n';
		if(i%100==0)
			cerr<<i<<'\n';
		test.close();
		solve(a,b);
	}
	cerr<<"STRESS OK HMM\n";
}
int main(){
#ifndef ONLINE_JUDGE
	stress();
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
//	n=99999;
	string a,b;
	cin>>a>>b;
	a.resize(n);
	b.resize(n);
	/*
	for(int i=0;i<n;i+=3){
		a[i]='1';
		b[i]='9';
		a[i+1]=b[i+1]='4';
		a[i+2]='9';
		b[i+2]='1';
	}
	*/
	solve(a,b);
}