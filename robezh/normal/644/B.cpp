#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

int n,d;
int a,b;
vector<ll> V;
vector<ll> res;

int main(){
	scanf("%d%d", &n, &d);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a, &b);
		if(V.empty()){
			V.push_back(a + b);
			res.push_back(a+b);
			continue;
		}
		int num = V.end() - upper_bound(V.begin(), V.end(), a);
		//cout << "num = " << num << endl;
		if(num > d) res.push_back(-1);
		else{
			//cout << "lastime : " << V[V.size()-1] << " a : " << a << endl;
			res.push_back(max(V[V.size()-1],(ll)a) + b);
			V.push_back(max(V[V.size()-1],(ll)a) + b);
		}
	}
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
}