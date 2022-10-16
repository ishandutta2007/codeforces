/*#include <stack>
#include <vector>
#include <cstdio>
using namespace std;
#define ll long long
#define Maxn 1000000
int n,a[Maxn+5],m,u[Maxn+5],cnt[Maxn+5];
ll ans;
bool fl[Maxn+5];
vector<int> d[Maxn+5];
int count(int x){
	int res=0;
	for(int i=0;i<(int)d[x].size();i++){
		res+=cnt[d[x][i]]*u[d[x][i]];
	}
	return res;
}
void update(int x,int y){
	for(int i=0;i<(int)d[x].size();i++){
		cnt[d[x][i]]+=y;
	}
}
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]=1;
		m=max(m,x);
	}
	ans=m;
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j+=i){
			d[j].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		u[i]=1;
	}
	for(int i=2;i<=m;i++){
		if(fl[i]){
			continue;
		}
		u[i]=-1;
		for(int j=i*2;j<=m;j+=i){
			fl[j]=1;
			if((j/i)%i==0){
				u[j]=0;
			}
			else{
				u[j]*=-1;
			}
		}
	}
	for(int g=1;g<=m;g++){
		stack<int> s;
		for(int i=m/g;i>0;i--){
			if(!a[i*g]){
				continue;
			}
			int c=count(i);
			while(c){
				if(gcd(i,s.top())==1){
					ans=max(ans,(ll)i*s.top()*g);
					c--;
				}
				update(s.top(),-1);
				s.pop();
			}
			s.push(i);
			update(i,1);
		}
		while(s.size()){
			update(s.top(),-1);
			s.pop();
		}
	}
	printf("%lld\n",ans);
	return 0;
}*/
#include <stack>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 1000000
#define ll long long
int a[Maxn+5];
vector<int> p[Maxn+5];
bool b[Maxn+5];
int mu[Maxn+5];
int cnt[Maxn+5];
stack<int> st;
int n;
template<typename Elem_1,typename Elem_2>
Elem_1 mx(Elem_1 a,Elem_2 b){
	return a>b?a:b;
}
int main(){
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]=1;
		ans=mx(ans,1ll*a[i]);
	}
	int m=ans;
	mu[1]=1;
	for(int i=1;i<=m;i++){
		for(int j=i+i;j<=m;j+=i){
			mu[j]-=mu[i];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j+=i){
			if(mu[i]!=0){
				p[j].push_back(i);
			}
			b[i]=b[i]||b[j];
		}
	}
	for(int i=m;i>0;i--){
		if(!b[i]){
			continue;
		}
		int num=0;
		for(int j=0;j<(int)p[i].size();j++){
			num+=mu[p[i][j]]*cnt[p[i][j]];
		}
		while(num>0){
			int lst=num;
			for(int j=0;j<(int)p[st.top()].size();j++){
				cnt[p[st.top()][j]]--;
				if(i%p[st.top()][j]==0){
					num-=mu[p[st.top()][j]];
				}
			}
			if(lst!=num){
				ans=mx(ans,1ll*i*st.top());
			}
			st.pop();
		}
		for(int j=0;j<(int)p[i].size();j++){
			cnt[p[i][j]]++;
		}
		st.push(i);
	}
	cout<<ans<<endl;
	return 0;
}