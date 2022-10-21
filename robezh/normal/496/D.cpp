#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> P;

vector<P> V;

int n;
int num[100005];
int ones[100005];
int twos[100005];
int win = 0;

int get_s(int t){
	int pos = 0;
	int res = 0;
	int wincnt[3] = {0,0,0};
	while(pos <= n){
		int onep = lower_bound(ones+pos, ones+n+1, t+ones[pos]) - ones;
		int twop = lower_bound(twos+pos, twos+n+1, t+twos[pos]) - twos;
		//cout << "onep, twop : " << onep <<" " << twop << endl;
		if(onep == n+1 && twop == n+1) return -1;
		if(onep < twop) pos = onep, wincnt[1]++;
		else pos = twop, wincnt[2] ++;
		
		
		if(pos == n){
			if(wincnt[win] > wincnt[3-win]) return wincnt[win];
			else return -1;
		} 
	}
	
	return 0;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &num[i]);
	for(int i = 0; i < n; i++){
		if(num[i] == 1) ones[i+1] = ones[i] + 1, twos[i+1] = twos[i];
		else twos[i+1] = twos[i] + 1, ones[i+1] = ones[i];
	}
	win = num[n-1];
	
	int maxt = (win == 1 ? ones[n] : twos[n]);
	for(int i = 1; i <= maxt; i++){
		int s = get_s(i);
		if(s != -1) V.push_back(P(s,i));
	}
	sort(V.begin(), V.end());
	cout << V.size() << endl;
	for(int i = 0; i < V.size(); i++){
		P p = V[i];
		printf("%d %d\n", p.first, p.second);
	}
	
}