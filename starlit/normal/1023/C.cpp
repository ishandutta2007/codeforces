#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,k,t,sum,ans[N],ta;
char S[N];
int main(){
	scanf("%d%d%s",&n,&k,S);k>>=1;
	for(int i=0;i<n;i++)
	if(S[i]=='('){
        if(sum<k)sum++,t++,ans[ta++]=1;
	}
	else{
        if(t)t--,ans[ta++]=-1;
	}
	for(int i=0;i<ta;i++)putchar(ans[i]>0?'(':')');
}