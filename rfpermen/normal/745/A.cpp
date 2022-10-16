#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define MAX 10005
using namespace std;
int n,cnt,y,l;
string s,x[100];
char lala;
string::iterator it;
//vector<string> x;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	cnt=0;
	x[cnt]=s;
	y=s.size();
	rep(i,0,y-1){
		lala=s[y-1];
		it = s.insert(s.begin(),lala);
		s.erase(s.begin()+y);
		rep(j,0,cnt){
			if(x[j]==s)break;
			else if(j==cnt)cnt++, x[cnt]=s;
		}
	}
	cout<<cnt+1<<endl;
}