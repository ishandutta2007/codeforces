#include<bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> h;
long long ans;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		h.push(-x),h.push(-x);
		int u=-h.top();
		ans+=x-u,h.pop();
	}
	printf("%I64d\n",ans);
	return 0;
}