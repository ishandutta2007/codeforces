#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <stdio.h>

#define MAX_N 200000
#define MAX_M (1<<30)
typedef long long ll;
using namespace std;

int N;
int M;
struct S{
	int up;
	int l=-1, r=-1;
	int cnt = 0;
};
S arr[MAX_N*30];
int sz = 0;
int two;
ll ans=0;
vector<int> v[MAX_N*30];
vector<int> num1, num2;

void update(int y){
	two = (1<<29);
	int idx = 0;
	while(1){
		arr[idx].cnt++;
		if(two==0)	break;
		if((y&two)==0){
			if(arr[idx].l==-1){
				arr[idx].l = ++sz;
				arr[arr[idx].l].up = idx;
			}
			idx = arr[idx].l;
		}else{
			if(arr[idx].r==-1){
				arr[idx].r = ++sz;
				arr[arr[idx].r].up = idx;
			}
			idx = arr[idx].r;
		}
		two/=2;
	}
	v[idx].push_back(y);
	num1.push_back(idx);
}

int calc(int x, int y){
	int ret = 0, nt = two;
	while(nt>0){
		if((x&nt)==0){
			if(arr[y].l!=-1 && arr[arr[y].l].cnt>0){
				y = arr[y].l;
			}else{
				ret+=nt;
				y = arr[y].r;
			}
		}else{
			if(arr[y].r!=-1 && arr[arr[y].r].cnt>0){
				y=arr[y].r;
			}else{
				ret+=nt;
				y=arr[y].l;
			}
		}
		nt/=2;
	}
	return ret;
}

int nxtt(int x){
	if(x==0)	return 1;
	return x*2;
}

void solve(){
	two = 0;
	//cout<<num1.size();
	while(!num1.empty()){
		if(num1[0]==0)	return;
		for(int i=0; i<num1.size(); i++){
			if(i!=num1.size()-1 && num1[i] == arr[arr[num1[i]].up].l && num1[i+1] == arr[arr[num1[i]].up].r){
				ll cost = (ll)((1<<31)-1);
				for(int j=0; j<v[num1[i]].size(); j++){
					cost = min(cost, (ll)calc(v[num1[i]][j], num1[i+1])+nxtt(two));
				}
				ans+=cost;
			}
		}
		for(int i=0; i<num1.size(); i++){
			if(v[arr[num1[i]].up].empty()){
				num2.push_back(arr[num1[i]].up);
			}
			for(int j=0; j<v[num1[i]].size(); j++){
				v[arr[num1[i]].up].push_back(v[num1[i]][j]);
			}
			v[num1[i]].clear();
		}
		num1.clear();
		for(int i=0; i<num2.size(); i++){
			num1.push_back(num2[i]);
		}
		num2.clear();
		two=nxtt(two);
	}
}



vector<int> in;

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &M);
		in.push_back(M);
	}
	sort(in.begin(), in.end());
	for(int i=0; i<in.size(); i++){
		if(i==0 || in[i] != in[i-1]){
			update(in[i]);
		}
	}
	sort(num1.begin(), num1.end());
	solve();
	printf("%lld", ans);
	return 0;
}