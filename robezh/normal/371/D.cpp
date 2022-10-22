#include<cstdio>
#include<set>
using namespace std;

set<int> S;
set<int>::iterator it;
int n;
int cap[200050];
int num[200050];
int k;
int r,p,q;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &num[i]), cap[i] = num[i];
	for(int i = 0; i < n; i++){
		S.insert(i);
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d", &r);
		if(r == 1){
			scanf("%d%d", &p, &q);
			
			it = S.lower_bound(p-1);
			while(q > 0 && S.size() > 0){
				if(it == S.end()) break;
				if(num[*it] > q){
					num[*it] -= q;
					break;
				}
				else{
					q -= num[*it];
					num[*it] = 0;
					//cout <<"mode2 : " << *it << endl;
					S.erase(it++);
					//cout << "mode2: " << *it << endl;
					//it = lower_bound(S.begin(), S.end(), p);
				}
			}
		}
		else{
			scanf("%d", &p);
			printf("%d\n", cap[p-1] - num[p-1]);
			//cout << cap[p-1] - num[p-1] << endl;
		}
	}
	
}