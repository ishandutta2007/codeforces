#include <bits/stdc++.h>
using namespace std;
const int N = 202;

struct Item {
	string pre, suf;
	set<int> st[22];
	void print() {
		cout << pre << " " << suf << endl;
	}
	void init() {
		string s; cin >> s;
		int n = s.length();
		for(int i=0;i<n;i++){
			int mask=0,len=0;
			for(int j=i;j<n;j++){
				mask=mask<<1|(s[j]-'0');
				len++;
				if(len<=20)st[len].insert(mask);
			}
		}
		for(int i=0;i<min(n,20);i++) pre=pre+s[i];
		for(int i=n-1;i>=max(n-20,0);i--) suf=s[i]+suf;
	}
	int getAns() {
		int ans=0;
		for (int i=1;;i++) {
			if(i==21) while(1);
			if(st[i].size() != (1<<i)) break;
			ans=i;
		}
		return ans;
	}
	Item operator + (const Item & o) const {
		Item ans; for(int i=0;i<22;i++) ans.st[i].clear(); ans.pre=ans.suf="";
		for(int i=0;i<22;i++){
			for(auto x:st[i]) ans.st[i].insert(x);
			for(auto x:o.st[i]) ans.st[i].insert(x);
		}
		ans.pre=pre;
		ans.suf=o.suf;
		int l1=20-pre.length();
		for(int i=0;i<l1&&o.pre[i];i++) ans.pre+=o.pre[i];
		int l2=20-o.suf.length();
		for(int i=suf.length()-1;i>=0;i--){
			l2--; if(l2<0)break;
			ans.suf=suf[i]+ans.suf;
		}
		for(int i=suf.length()-1;i>=0;i--) {
			for(int j=0;o.pre[j];j++) {
				//printf("i=%d,j=%d\n", i,j);
				int mask=0;
				for(int x=i;suf[x];x++) mask=mask<<1|(suf[x]-'0');
				for(int x=0;x<=j;x++) mask=mask<<1|(o.pre[x]-'0');
				//printf("mask = %d\n", mask);
				if(suf.length()-i+j+1 <= 20)
				ans.st[suf.length()-i+j+1].insert(mask);
			}
		}

		return ans;
	}
} it[N];
int n,m;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) it[i].init();
	cin>>m;
	for(int i=n+1;i<=n+m;i++) {
		int x,y; scanf("%d%d",&x,&y);
		it[i]=it[x]+it[y];
		cout<<it[i].getAns()<<endl;
	}
}