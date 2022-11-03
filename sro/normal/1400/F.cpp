/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define loop(i,n) for(int i=0;i<(n);i++)
#define cont(i,n) for(int i=1;i<=(n);i++)
#define circ(i,a,b) for(int i=(a);i<=(b);i++)
#define range(i,a,b,c) for(int i=(a);((c)>0?i<=(b):i>=(b));i+=(c))
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(),_e_D_=(v).end();it!=_e_D_;it++)
#define y0 y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1 y1II11II11III11I1III11II111IIII1II1I1
#define pub push_back
#define pob pop_back
#define mak make_pair

typedef long long ll;
typedef long double lf;
const int Inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int n,x;
char s[5544];
vector<int> st;
int sm,nds;
int tr[5544][10],fail[5544];
bool is[5544];
int dp[5544][5544];

void find(){
	if(st.size()&&sm==x){
		int now=0;
		loop(i,st.size()){
			if(!tr[now][st[i]])
				tr[now][st[i]]=++nds;
			now=tr[now][st[i]];
		}
		is[now]=1;
		return;
	}
	if(sm>=x)return;
	cont(i,9){
		if(x!=i&&x%i==0)continue;
		int ss=i,can=1;
		range(j,st.size()-1,0,-1){
			ss+=st[j];
			if(x!=ss&&x%ss==0){
				can=0;
				break;
			}
		}
		if(can){
			st.pub(i);sm+=i;
			find();
			st.pob();sm-=i;
		}
	}
}

int main(){
	scanf("%s",s+1);
	scanf("%d",&x);
	n=strlen(s+1);
	find();
	queue<int> q;
	loop(i,10)if(tr[0][i]){
		fail[tr[0][i]]=0;
		q.push(tr[0][i]);
	}
	while(q.size()){
		int x=q.front();q.pop();
		is[x]|=is[fail[x]];
		cont(i,9){
			if(tr[x][i]){
				fail[tr[x][i]]=tr[fail[x]][i];
				q.push(tr[x][i]);
			}else{
				tr[x][i]=tr[fail[x]][i];
			}
		}
	}
	loop(i,n+1)loop(j,nds+1)dp[i][j]=Inf;
	dp[0][0]=0;
	loop(i,n)loop(j,nds+1){
		if(dp[i][j]==Inf)continue;
		dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
		if(!is[tr[j][s[i+1]-'0']])
			dp[i+1][tr[j][s[i+1]-'0']]=min(dp[i+1][tr[j][s[i+1]-'0']],dp[i][j]);
	}
	int ans=Inf;
	loop(j,nds+1)ans=min(ans,dp[n][j]);
	printf("%d\n",ans);
	return 0;
}