#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define hp se.fi
#define dmg se.se
const ll MAX=100005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,x[MAX],bef,dif,cnt,mn,st,f1,f2;
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;mn=n;
	rep(i,1,n)cin>>x[i];
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	dif=x[2]-x[1];
	//dif-2;
	bef=x[2]-1;cnt=2;f1=1;
	rep(i,3,n){
		st=abs(x[i]-bef-(dif-2));
		if(st>1){
			f1=0; break;
		}
		if(st==0){
			bef=x[i]; continue;
		}
		st=(x[i]-bef-(dif-2));
		bef=x[i]-st; cnt++;
	}
	if(f1)mn=min(cnt,mn),f2=1;
	//dif-1
	bef=x[2]-1;cnt=1;f1=1;
	rep(i,3,n){
		st=abs(x[i]-bef-(dif-1));
		if(st>1){
			f1=0; break;
		}
		if(st==0){
			bef=x[i]; continue;
		}
		st=(x[i]-bef-(dif-1));
		bef=x[i]-st; cnt++;
	}
	if(f1)mn=min(cnt,mn),f2=1;
	bef=x[2];cnt=1;f1=1;
	rep(i,3,n){
		st=abs(x[i]-bef-(dif-1));
		if(st>1){
			f1=0; break;
		}
		if(st==0){
			bef=x[i]; continue;
		}
		st=(x[i]-bef-(dif-1));
		bef=x[i]-st; cnt++;
	}
	if(f1)mn=min(cnt,mn),f2=1;
	//dif+0
	bef=x[2];cnt=0;f1=1;
	rep(i,3,n){
		st=abs(x[i]-bef-(dif));
		if(st>1){
			f1=0; break;
		}
		if(st==0){
			bef=x[i]; continue;
		}
		st=(x[i]-bef-(dif));
		bef=x[i]-st; cnt++;
	}
	if(f1)mn=min(cnt,mn),f2=1;
	bef=x[2]+1;cnt=2;f1=1;
	rep(i,3,n){
		st=abs(x[i]-bef-(dif));
		if(st>1){
			f1=0; break;
		}
		if(st==0){
			bef=x[i]; continue;
		}
		st=(x[i]-bef-(dif));
		bef=x[i]-st; cnt++;
	}
	if(f1)mn=min(cnt,mn),f2=1;
	bef=x[2]-1;cnt=2;f1=1;
	rep(i,3,n){
		st=abs(x[i]-bef-(dif));
		if(st>1){
			f1=0; break;
		}
		if(st==0){
			bef=x[i]; continue;
		}
		st=(x[i]-bef-(dif));
		bef=x[i]-st; cnt++;
	}
	if(f1)mn=min(cnt,mn),f2=1;
	//dif+1
	bef=x[2];cnt=1;f1=1;
	rep(i,3,n){
		st=abs(x[i]-bef-(dif+1));
		if(st>1){
			f1=0; break;
		}
		if(st==0){
			bef=x[i]; continue;
		}
		st=(x[i]-bef-(dif+1));
		bef=x[i]-st; cnt++;
	}
	if(f1)mn=min(cnt,mn),f2=1;
	bef=x[2]+1;cnt=1;f1=1;
	rep(i,3,n){
		st=abs(x[i]-bef-(dif+1));
		if(st>1){
			f1=0; break;
		}
		if(st==0){
			bef=x[i]; continue;
		}
		st=(x[i]-bef-(dif+1));
		bef=x[i]-st; cnt++;
	}
	if(f1)mn=min(cnt,mn),f2=1;
	//dif+2
	bef=x[2]+1;cnt=2;f1=1;
	rep(i,3,n){
		st=abs(x[i]-bef-(dif+2));
		if(st>1){
			f1=0; break;
		}
		if(st==0){
			bef=x[i]; continue;
		}
		st=(x[i]-bef-(dif+2));
		bef=x[i]-st; cnt++;
	}
	if(f1)mn=min(cnt,mn),f2=1;
	if(f2)cout<<mn<<endl;
	else cout<<-1<<endl;
    return 0;
}