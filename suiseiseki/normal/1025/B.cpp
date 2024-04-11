#include <cstdio>
#include <set>
using namespace std;
set<int> p;
set<int>::iterator it,now;
void work(int x,int y){
	it=p.begin();
	while(it!=p.end()){
		if(x%(*it)!=0&&y%(*it)!=0){
			now=it;
			it++;
			p.erase(now);
		}
		else{
			it++;
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=2;i*i<=a;i++){
		if(a%i==0){
			p.insert(i);
			while(a%i==0){
				a/=i;
			}
		}
	}
	if(a>1){
		p.insert(a);
	}
	for(int i=2;i*i<=b;i++){
		if(b%i==0){
			p.insert(i);
			while(b%i==0){
				b/=i;
			}
		}
	}
	if(b>1){
		p.insert(b);
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		work(a,b);
	}
	if(p.empty()){
		puts("-1");
	}
	else{
		printf("%d\n",(*p.begin()));
	}
	return 0;
}