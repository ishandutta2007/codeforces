#include <stack>
#include <cstdio>
using namespace std;
#define Maxn 200000
int n;
char s[Maxn+5];
stack<int> st;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			sum++;
		}
		else{
			sum--;
		}
	}
	if(sum!=0){
		puts("No");
		return 0;
	}
	int ans;
	sum=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			st.push(i);
		}
		else{
			if(!st.empty()){
				st.pop();
			}
		}
	}
	ans=(int)st.size();
	if(ans<=1){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}