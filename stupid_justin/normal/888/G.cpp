#include <iostream>
using namespace std;
int const N=30,M=2e5+5;
struct tree{
  int son[2],d;
}t[N*M]; 
int n;
long long ans,pow[N],a[M],root,tot,r;
void connect(int x, int y,long long now){
  if (t[x].d==N){
  	if (now<r) r=now;
  	return;
  }
  bool flag=false;
  for (int i=0;i<=1;i++)
  	if (t[x].son[i] && t[y].son[i]){
  		connect(t[x].son[i],t[y].son[i],now);
  		flag=true;
  	}
  if (!flag){
  	if (t[x].son[0] && t[y].son[1]) connect(t[x].son[0],t[y].son[1],now+pow[N-t[x].d-1]);
  	else connect(t[x].son[1],t[y].son[0],now+pow[N-t[x].d-1]);
  }
}
void dfs(int x){
  if (!x || t[x].d==N) return;
  for (int i=0;i<=1;i++) dfs(t[x].son[i]);
  if (t[x].son[0] && t[x].son[1]){
  	r=2e9;
  	connect(t[x].son[0],t[x].son[1],pow[N-t[x].d-1]);
  	ans=ans+r;
  }
}
int main(){
  pow[0]=1;
  for (int i=1;i<N;i++) pow[i]=pow[i-1]+pow[i-1];
  cin>>n;
  root=tot=1;
  for (int i=1;i<=n;i++){
  	cin>>a[i];
  	int x=root; 
  	for (int j=0;j<N;j++){
  		int r=((pow[N-j-1] & a[i])>0);
  		if (!t[x].son[r]){
  			t[x].son[r]=++tot;
  			t[tot].d=t[x].d+1;
  		}
  		x=t[x].son[r];
  	} 
  }
  dfs(1);
  cout<<ans<<endl;
  return 0;
}