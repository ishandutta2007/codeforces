#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
const LL inf = 1e18 + 7;
LL k,l,r,t,x,y;
bool visit[N];
LL add(LL x, LL y) {
	return min(x+y,inf);
}
pair<LL,LL> trans(LL low, LL high, LL pos) {
	LL days = 1, cur = pos + y - x;
	if (cur <= high) {
		//printf("days = %lld, cur = %lld\n", days, cur);
		return make_pair(cur, days);
	}
	LL add = (cur - high + x - 1) / x;
	days += add;
	return make_pair(cur - add * x, days);
}

LL solveMid(LL low, LL high,LL pos) {
	//printf("# solveMid %lld %lld %lld\n", low, high, pos);
	if (visit[pos - low] == 1) return inf;
	visit[pos - low] = 1;
	pair<LL,LL> nex = trans(low,high,pos); 
	
	if (nex.first < low) {
		return nex.second - 1;
	}
	return add(nex.second, solveMid(low, high, nex.first));
}
LL solveUp(LL low, LL high, LL pos) {
	assert(pos > high);
	LL days = (pos - high + x - 1) / x;
	LL to = pos - x * days;
	if (to < low) return days - 1;
	//printf("days = %lld\n", days);
	return add(days, solveMid(low, high, to));
}
LL solveDown(LL low,LL high,LL pos){
	assert(pos < low);
	LL dt = y - x;
	LL need = low - pos;
	LL days = (need + dt - 1) / dt;

	LL to = pos + days * dt;
	//printf("to = %lld\n", to);
	if (to > high) return days + solveUp(low,high,to);
	else if (to <= high) return days + solveMid(low,high,to); 
	return inf;
}
LL solve(){
	if (y > r) {
		return k / x;
	} 
	if (y <= x) {
		if (k + y <= r) {
			if (x == y) return inf;
			return k / (x - y);
		}else{
			LL cur = k;
			if (cur - x < 0) return 0;
			cur -= x; 
			if (x == y) return inf;
			return 1 + cur / (x - y);
		}
	}

	LL low = max(r - y - x + 1, 0LL);
	LL high = r - y;
	//printf("low=%lld,high=%lld,k=%lld\n", low,high,k);
	if (k > high) return solveUp(low,high,k);
	else if(k>=low && k<=high) return solveMid(low,high,k);
	return solveDown(low,high,k);
	// x = pos - low	 


}
LL brt(){
	LL ans=0;
	LL cur=k;
	set<LL> vis;

	while(true) {
		if(cur + y <= r) {
			cur += y;
		}
		if (cur >= x) {
			cur -= x; 
			if (vis.count(cur)) return inf;
			vis.insert(cur);
			ans ++;
		}else{
			break;
		}
	}
	return ans;
}	
void test() {
	memset(visit,0,sizeof(visit));
	l=0,r=rand()%10000000+10;k=rand()%(r+1);x=rand()%100000+1,y=rand()%100000+1;
	//assert(brt() == solve());
	//cout << brt() << " " << solve() << endl;
	printf("%lld %lld %lld %lld %lld %lld\n", k,l,r,t,x,y);
	cout<<solve()<<endl;
}

int main() {
	
	for(int i=1;i<=1000;i++){
		//test();
	}
	
	scanf("%lld%lld%lld%lld%lld%lld",&k,&l,&r,&t,&x,&y);


	r -= l, k -= l, l = 0;
	//printf("%lld %lld %lld %lld %lld %lld\n", k,l,r,t,x,y);
	//cout << brt() << " " << solve() << endl;
	printf("%s\n", solve() >= t ? "Yes" : "No");
}

/*
5 0 6 10 2 7
*/