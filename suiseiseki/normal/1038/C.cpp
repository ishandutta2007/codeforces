#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
priority_queue<int> qa,qb;
int main(){
	int n;
	scanf("%d",&n);
	int a;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		qa.push(a);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		qb.push(a);
	}
	long long ans_a=0,ans_b=0;
	while(!qa.empty()||!qb.empty()){
		if(qa.empty()){
			qb.pop();
		}
		else{
			if(qb.empty()||qa.top()>qb.top()){
				ans_a+=qa.top();
				qa.pop();
			}
			else{
				qb.pop();
			}
		}
		if(qb.empty()){
			qa.pop();
		}
		else{
			if(qa.empty()||qb.top()>qa.top()){
				ans_b+=qb.top();
				qb.pop();
			}
			else{
				qa.pop();
			}
		}
	}
	cout<<ans_a-ans_b<<endl;
	return 0;
}
   ///////