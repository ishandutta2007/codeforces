#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

long long ax, ay, bx, by, t, maxx, maxy;
struct node{
	long long x, y;
	node next(){
		return (node){ax * x + bx, ay * y + by};
	}
	node last(){
		return (node){(x - bx) / ax, (y - by) / ay};
	}
}hd, s;
long long dist(const node &a, const node &b){
	return abs(a.x - b.x) + abs(a.y - b.y);
}
int ans;

void getans(const node &p){
	if(dist(s, p) > t) return;
	int cnt = 1;
	node q = p;
	while((q.x != hd.x || q.y != hd.y) && dist(s, p) + dist(p, q.last()) <= t)
		++cnt, q = q.last();
	ans = max(ans, cnt);
	cnt = 1;
	q = p;
	while(q.x <= maxx && q.y <= maxy && dist(s, p) + dist(p, q.next()) <= t)
		++cnt, q = q.next();
	ans = max(ans, cnt);
}

int main(){
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", 
	&hd.x, &hd.y, &ax, &ay, &bx, &by, &s.x, &s.y, &t);
	maxx = ((long long)(2e16) - bx) / ax;
	maxy = ((long long)(2e16) - by) / ay;
	node p = hd;
	getans(p);
	while(p.x <= maxx && p.y <= maxy)
		getans(p = p.next());
	printf("%d", ans);
	return 0;
}