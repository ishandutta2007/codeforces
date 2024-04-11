#include <cstdio>
#include <stack>
using namespace std;
char s[200005];
bool no[200005];
stack<int> st;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;k<n&&i<=n;i++){
		if(s[i]=='('){
			st.push(i);
		}
		else{
			no[st.top()]=1;
			no[i]=1;
			st.pop();
			k+=2;
		}
	}
	for(int i=1;i<=n;i++){
		if(!no[i]){
			putchar(s[i]);
		}
	}
	puts("");
	return 0;
}