#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair

int a[30][30];

int main(){
	string s,t,qqq;
	cin>>s>>t;
	if(s.size()!=t.size()){
		cout<<-1;
		return 0;
	}
	int n;
	cin>>n;
	forn(i,30)
		forn(j,30)
			a[i][j]=1000000000;
	forn(i,30)
		a[i][i]=0;
	forn(i,n){
		char x, y;
		int s;
		cin>>x>>y>>s;
		a[x-'a'][y-'a']=min(a[x-'a'][y-'a'],s);
	}
	forn(i,30)
		forn(j,30)
			forn(k,30)
				forn(l,30)
					a[j][k]=min(a[j][k],a[j][l]+a[l][k]);
	long long ans=0;
	forn(i,s.size()){
		int mn=1000000000;
		char q;
		int l=s[i]-'a';
		int r=t[i]-'a';
		forn(j,30){
			int qq=a[l][j]+a[r][j];
			if(qq<mn){
				mn=qq;
				q='a'+j;
			}
		}
		ans+=mn;
		qqq+=q;
	}
	if(ans<1000000000)
		cout<<ans<<endl<<qqq;
	else
		cout<<-1;
	return 0;
}