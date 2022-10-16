#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
const int MAX=50;
int n,k,lel[MAX],lol[MAX],lil[MAX],cnt,stat;
char x;
string s,t;
int main(){
	cin>>s;
	cin>>t;
	rep(i,0,s.size()-1){
		if(s[i]=='?')cnt++;
		else lol[s[i]-'a'+1]++;
	}
	rep(i,0,t.size()-1)lel[t[i]-'a'+1]++;
	while(cnt>0){
		rep(i,1,26){
			lol[i]-=lel[i];
		}
		rep(i,1,26){
			if(lol[i]<0){
				lil[i]+=min(cnt,-lol[i]);
				if(cnt+lol[i]>=0)cnt+=lol[i], lol[i]=0;
				else lol[i]+=cnt, cnt=0;
			}
		}
	}
	rep(i,0,s.size()-1){
		if(s[i]=='?'){
			rep(i,1,26){
				if(lil[i]){
					lil[i]--;
					x=i+'a'-1;
					cout<<x;
					break;
				}
			}
		}
		else cout<<s[i];
	}
	cout<<endl;
	return 0;
}