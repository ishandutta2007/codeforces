#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;


map<ll, P> M;
int n;
ll num[100050];
ll sum = 0;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num[i];
		sum += num[i];
		if(!M.count(num[i])) M[num[i]] = P(i,i);
		else{
			P p = M[num[i]];
			M[num[i]] = P(min(p.first, i), max(p.second, i));
		}
	}
	if(sum % 2 == 1) return !printf("NO");
	ll avrg = sum / 2;
	ll tot = 0;
	if(M.count(avrg)) return !printf("YES");
	for(int i = 0; i < n; i++){
		tot += num[i];
		if(tot == avrg) return !printf("YES");
		else if(tot > avrg){
			ll k = tot - avrg;
			if(M.count(k) && M[k].first <= i) return !printf("YES");
		}
		else{
			ll k = avrg - tot;
			if(M.count(k) && M[k].second > i) return !printf("YES");
		}
	}
	return !printf("NO");
}