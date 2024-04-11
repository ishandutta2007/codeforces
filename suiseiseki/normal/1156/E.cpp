#include <cstdio>
#include <stack>
using namespace std;
#define Maxn 200000
int a[Maxn+5];
stack<int> st;
int id[Maxn+5];
int l[Maxn+5],r[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		id[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		l[i]=1;
		while(!st.empty()&&st.top()<a[i]){
			st.pop();
		}
		if(!st.empty()){
			l[i]=id[st.top()]+1;
		}
		st.push(a[i]);
	}
	while(!st.empty()){
		st.pop();
	}
	for(int i=n;i>0;i--){
		r[i]=n;
		while(!st.empty()&&st.top()<a[i]){
			st.pop();
		}
		if(!st.empty()){
			r[i]=id[st.top()]-1;
		}
		st.push(a[i]);
	}
	int ans=0;
	int now;
	for(int i=1;i<=n;i++){
		if(i-l[i]<r[i]-i){
			for(int j=i-1;j>=l[i];j--){
				now=a[i]-a[j];
				if(id[now]>i&&id[now]<=r[i]){
					ans++;
				}
			}
		}
		else{
			for(int j=i+1;j<=r[i];j++){
				now=a[i]-a[j];
				if(id[now]<i&&id[now]>=l[i]){
					ans++;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}