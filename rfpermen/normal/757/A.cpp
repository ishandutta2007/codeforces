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
string s;
int x[7],siz;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	siz=s.size();
	rep(i,0,siz-1){
		if(s[i]=='B')x[0]++;
		else if(s[i]=='u')x[1]++;
		else if(s[i]=='l')x[2]++;
		else if(s[i]=='b')x[3]++;
		else if(s[i]=='a')x[4]++;
		else if(s[i]=='s')x[5]++;
		else if(s[i]=='r')x[6]++;
	}
	x[1]/=2, x[4]/=2;
	cout<<min(min(min(min(min(min(x[0],x[1]),x[2]),x[3]),x[4]),x[5]),x[6])<<endl;
	return 0;
}