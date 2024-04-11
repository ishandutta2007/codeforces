#include <cstdio>
#include <set>
using namespace std;
#define Maxn 1000
multiset<int> st;
int a[Maxn+5];
int n,h;
bool check(){
	multiset<int>::iterator it;
	it=st.end();
	it--;
	int ans=0;
	do{
		ans+=(*it);
		if(ans>h){
			break;
		}
		if(it!=st.begin()){
			it--;
			if(it!=st.begin()){
				it--;
				if(it==st.begin()){
					ans+=(*it);
				}
			}
		}
	}while(it!=st.begin());
	return ans<=h;
}
int main(){
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		st.insert(a[i]);
	}
	multiset<int>::iterator it;
	for(int i=n;i>0;i--){
		if(check()){
			printf("%d\n",i);
			break;
		}
		it=st.find(a[i]);
		st.erase(it);
	}
	return 0;
}