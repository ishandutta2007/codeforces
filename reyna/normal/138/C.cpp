//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 9;
typedef long double ld;
int pl[Maxn],h[Maxn];
long double lp[Maxn],rp[Maxn];
int b[Maxn],z[Maxn];
ld fromleft[Maxn],fromright[Maxn];
pair<int,int> sweep[Maxn];
int bg,ed;
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n;i++){
		cin >> pl[i] >> h[i];
		int prol,pror;
		cin >> prol >> pror;
		lp[i] = (long double)prol / 100,rp[i] = (long double)pror / 100;
		sweep[i * 2] = make_pair(pl[i] + h[i],i + m);
		sweep[i * 2 + 1] = make_pair(pl[i],i + m);
	}
	for(int i = 0; i < m;i++){
		cin >> b[i] >> z[i];
		sweep[2 * n + i] = make_pair(b[i],i);
	}
	sort(sweep,sweep + 2 * n + m);
	int ed = 2 * n + m;
	ld cur = 1;
	int is_zero = 0;
	for(int i = 0; i < ed;i++){
		int place = sweep[i].first,id = sweep[i].second;
		if(id >= m){
			id -= m;
			if(rp[id] == 1){
				if(place != pl[id]) is_zero--;
				else is_zero++;
				continue;
			}
			if(place != pl[id]) cur /= 1 - rp[id];
			else cur *= 1 - rp[id]; 
		}else{
			if(!is_zero) fromleft[id] = cur;
		}
	}
	cur = 1;
	for(int i = 0; i < n;i++){
		sweep[i * 2] = make_pair(pl[i] - h[i],-(i + m));
		sweep[i * 2 + 1] = make_pair(pl[i],-(i+m));
	}
	for(int i = 0; i < m;i++) sweep[2 * n + i] = make_pair(b[i],i);
	sort(sweep,sweep+ed);
	reverse(sweep,sweep+ed);
	is_zero = 0;
	for(int i = 0; i < ed;i++){
		int place = sweep[i].first,id = sweep[i].second;
		if(id < 0){
			id = -id;
			id -= m;
			if(lp[id] == 1){
				if(place != pl[id]) is_zero--;
				else is_zero++;
				continue;
			}
			if(place != pl[id]) cur /= (1 - lp[id]);
			else cur *= (1 - lp[id]);
		}else{
			if(!is_zero) fromright[id] = cur;
		}
	}
	ld ans = 0;
	for(int i = 0; i < m;i++){
		ans += fromleft[i] * fromright[i] * z[i];
	}
	cout << setprecision(10) << fixed << ans << endl;
	return 0;
}