#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef pair<bool,pair<int,int> > pos;

string s[100];
string v[30000];
vector<int> e[30000];
int c[30000],num[30000];
pos ans[30000];
int m;
bool u[30000];

void dfs(int n){
	if(u[n])
		return;
	u[n]=1;
	ans[n]=mp(0,mp(-1,0));
	forn(i,e[n].size()){
		dfs(e[n][i]);
		pos next=ans[e[n][i]];
		pos now = mp( !next.fs, mp( -next.sc.sc, -next.sc.fs ) );
		ans[n]=max(ans[n],now);
	}
	if(ans[n].sc.fs<0)
		ans[n]=mp(0,mp(0,0));
	if(n!=0)
		ans[n].sc.sc-=c[n];
	return;
}

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	forn(i,30000)
		u[i]=0;
	int n;
	cin>>n;
	forn(i,n)
		cin>>s[i];
	m=0;
	forn(i,n){
		int m1=m;
		forn(r,s[i].size())
			forn(l,r+1){
				v[m]=s[i].substr(l,r-l+1);
				m++;
			}
		sort(v+m1,v+m);
		int m0=m1+1;
		for(int i=m1+1; i<m; i++)
			if(v[i]!=v[m0-1]){
				v[m0]=v[i];
				m0++;
			}
		m=m0;
	}
	sort(v,v+m);
	ford(i,m)
		v[i+1]=v[i];
	v[0]="";
	m++;
	{
		forn(i,m)
			num[i]=0;
		int m0=1;
		for(int i=1; i<m; i++){
			if(v[i]!=v[m0-1]){
				v[m0]=v[i];
				m0++;
			}
			num[m0-1]++;
		}
		m=m0;
	}
	forn(i,m)
		forn(j,52){
			string q;
			if(j<26)
				q=v[i]+(char)('a'+j);
			else
				q=(char)('a'+j-26)+v[i];
			int l=1, r=m-1;
			while(l<r){
				int mid=(l+r)/2;
				if(q>v[mid])
					l=mid+1;
				else
					r=mid;
			}
			if(q==v[l])
				e[i].pb(l);
		}
	forn(i,m){
		int sval=0,mval=0;
		forn(j,v[i].size()){
			int c=v[i][j]-'a'+1;
			sval+=c;
			mval=max(mval,c);
		}
		c[i]=sval*mval+num[i];
	}
//	forn(i,m){
//		cout<<v[i];
//		forn(j,e[i].size())
//			cout<<' '<<e[i][j];
//		cout<<endl;
//	}
//	cout<<endl<<endl;
	dfs(0);
	printf("%s\n%d %d",ans[0].fs ? "First" : "Second", ans[0].sc.fs, -ans[0].sc.sc);
	return 0;
}